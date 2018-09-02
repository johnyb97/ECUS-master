# Copyright (c) 2017 Patrik Bachan
#
# GNU GENERAL PUBLIC LICENSE
#    Version 3, 29 June 2007
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.



TOOLCHAIN		 = arm-none-eabi
export CC		 = $(TOOLCHAIN)-gcc
LD				 = $(CC)
OBJCOPY			 = $(TOOLCHAIN)-objcopy
SIZE			 = $(TOOLCHAIN)-size
OPTIMIZE		 = 0
LSCRIPT			 = stm32f746.ld
JOBS			 = 9
BLdev			 = /dev/ttyUSB0

SIZE_HISTORY	 = size.log
BUILD_NUM		 = $(shell wc -l $(SIZE_HISTORY)|cut -d " " -f1)
CMSIS_PATH		 = $(HOME)/dev/CMSIS/CMSIS

CLEAN_EXCLUDE	 = nk.o #main.o

DEFINES			 = -D 'BUILD=$(BUILD_NUM)' -Dtimegm=mktime
INCLUDES		 = -I./ -I$(CMSIS_PATH)/Core/Include/ -I$(CMSIS_PATH)/DSP/Include/ -I$(CMSIS_PATH)/DSP/Source/
MCU_OPTS		 = -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16
W_ERRORS		 = -Werror=switch -Werror=incompatible-pointer-types -Werror-implicit-function-declaration -Werror=int-conversion
W_IGNORED		 = -Wno-unused-function
VALIDATION_OPTS	 = -Wunused -Wall -Wextra -Wstrict-prototypes -Wundef $(W_ERRORS) $(W_IGNORED) -std=gnu11
OPTIMIZATIONS	 = -funsigned-char -funsigned-bitfields -fdata-sections -ffunction-sections -fdiagnostics-color=always

export CFLAGS    = $(DEFINES) -c $(VALIDATION_OPTS) -g -O$(OPTIMIZE) $(INCLUDES) $(MCU_OPTS) $(OPTIMIZATIONS) -fdata-sections -ffunction-sections


LDFLAGS			 = $(MCU_OPTS) -O$(OPTIMIZE) -Xlinker -Map=output.map -lm -nostartfiles --specs=nosys.specs -fdiagnostics-color=always -Wl,--gc-sections -T$(LSCRIPT)
TARGET			 = main

# select what to compile
SOURCES = $(wildcard ./*.c)
SOURCES += $(wildcard candb/*.c)
SOURCES += $(wildcard icons/*.c)

WRITTEN = $(wildcard ./*.c)
WRITTEN += $(wildcard ./*.h)
WRITTEN += $(wildcard ./helpers/*)
IGNORED = ./stm32f746xx.h ./gpio_gen.h ./candb_structure.c ./candb_structure.h ./font_minimized_ecus_font_default.c ./font_minimized_ecus_font_large.c
WRITTEN := $(filter-out $(IGNORED), $(WRITTEN))

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
export OBJECTS

export DEPS = $(patsubst %.o, %.d, $(OBJECTS))

# color codes
export color0 = \e[1;30m
#red
export color1 = \e[1;31m
#green
export color2 = \e[1;32m
#yellow
export color3 = \e[1;33m
#blue
export color4 = \e[1;34m
#pink
export color5 = \e[1;35m
export color6 = \e[1;36m
export color7 = \e[1;37m

export colorend = \e[0m

export color_stage = $(color5)
export color_action = $(color4)
export color_action_item = $(color6)
export color_action_ok = $(color2)

export separator = >>>>>>>>>>>>>>>>>>>>>>

stage = @printf "%b" "$(color_stage)$(separator)  $(1)$(colorend)\n"
action = @printf "%b" "$(color_action)$(1) $(color_action_item)$(2)$(colorend)"
export action_ex = $(value action)

action_ok = @printf "%b" "$(color_action_ok) DONE$(colorend)\n"
export action_ok_ex = $(value action_ok)


.NOTPARALLEL:

all: $(TARGET).hex

%.hex: %.elf
	$(call stage,HEX)
	$(OBJCOPY) -Oihex  $^ $@

%.elf: $(OBJECTS)
	$(call stage,LINK)
	$(call action,Linking...)
	$(LD) -o $@ $(OBJECTS) $(LDFLAGS)
	$(call action_ok)

	@$(SIZE) -B -d $@ | tail -n 1 >> $(SIZE_HISTORY)
	@#ignore non unique builds
	@uniq $(SIZE_HISTORY) $(SIZE_HISTORY).unique
	@mv $(SIZE_HISTORY).unique $(SIZE_HISTORY)
	@echo "BUILD $(BUILD_NUM)"


$(OBJECTS):
	$(call stage,COMPILE)
	$(call action,Starting parallel build...,\n)
	@$(MAKE) --no-print-directory --output-sync=target -f Makefile.compile

-include $(DEPS)

.PHONY: size
size: $(TARGET).elf
	$(call stage,SIZE)
	$(SIZE) -B -d $<

.PHONY: clean
clean:
	$(call stage,CLEAN)
	$(call action,Cleaning build files except $(CLEAN_EXCLUDE) ...)
	@find . -name '*.o' $(patsubst %, ! -name %, $(CLEAN_EXCLUDE)) -type f -exec rm -f {} +
	@rm -rf  $(TARGET).elf $(TARGET).hex
	$(call action_ok)
	$(call action,Cleaning dependency files...)
	@rm -rf *.d
	$(call action_ok)

.PHONY: fullclean
fullclean:
	$(call stage,CLEAN)
	$(call action,Cleaning ALL build files...)
	@rm -rf *.o $(TARGET).elf $(TARGET).hex
	$(call action_ok)
	$(call action,Cleaning dependency files...)
	@rm -rf *.d
	$(call action_ok)

.PHONY: burn
burn: $(TARGET).hex
	$(call stage,BURN)
	openocd -f openocd.cfg -c "init; reset halt; flash write_image erase $<; reset run; exit"

.PHONY: reset
reset:
	openocd -f openocd.cfg -c "init; reset run; exit"

.PHONY: debug
debug: $(TARGET).hex
	openocd -l openocd.log -f openocd.cfg -c "init; reset halt; flash write_image erase $<"&
	arm-none-eabi-gdb main.elf -ex "target extended-remote localhost:3333" -ex "monitor reset halt"
	echo "shutdown" | nc localhost 4444


.PHONY: trace
trace:
	@date > trace.log
	@echo -e "Trace start...\n" >> trace.log
	openocd -l openocd.log -f openocd.cfg -c "tpiu config internal trace.log uart off 200000000 2000000"&
	$(call action,Line buffered! CTRL+C to stop)
	$(call action,\nTracing...)
	@echo -e "\n"
	@tail -f trace.log
	echo "shutdown" | nc localhost 4444

.PHONY: peek
peek: $(TARGET).hex
	openocd -l openocd.log -f openocd.cfg -c "init"&
	arm-none-eabi-gdb main.elf -ex "target extended-remote localhost:3333"
	echo "shutdown" | nc localhost 4444

.PHONY: candb_update
candb_update:
	$(call stage,CANdb code update)
	$(call action,downloading...)
	@helpers/update_candb_code.sh
	$(call action_ok)
	$(call action,unpacking sources...)
	@unzip -q -o candb_tmp.zip -d ./candb/
	@rm candb_tmp.zip
	$(call action_ok)
	$(call action,generating structure...)
	@helpers/candb_struct_gen.py candb_export.json candb_structure > /dev/null
	$(call action_ok)

.PHONY: loc
loc:
	@cloc $(WRITTEN) 
	# wc -l $(WRITTEN) 
