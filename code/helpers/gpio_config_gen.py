#!/usr/bin/env python3

filename = "gpio_gen.h"

PORTS = ["A","B","C","D","E","F","G","H","I"]
PINS = 16

CLK_EN_REG = "AHB1ENR"

HEADER = """
/*This code was generated! Do not edit directly!*/
"""
FOOTER = """/*That is all!*/"""

print("Generating C GPIO config file...")

f=open(filename,"w")
f.write(HEADER)

for port in PORTS:
    for pin in range(PINS):
        prefix="P{}_{}_".format(port,pin)
        pinconfig="""
#ifndef """+prefix+"""MODE
    #define """+prefix+"""MODE      GPIO_MODE_ANALOG
    #define """+prefix+"""PUPD      GPIO_PUPD_NONE
    #define """+prefix+"""OSPEED    GPIO_OSPEED_LOW
    #define """+prefix+"""OTYPE     GPIO_OTYPE_PP
    #define """+prefix+"""AF        GPIO_AF0
    #define """+prefix+"""DEFAULT_STATE 0
#else
    #if ("""+prefix+"""MODE	== GPIO_MODE_ALTERNATE)
        #ifndef """+prefix+"""AF
            #error 'MODE = GPIO_MODE_ALTERNATE, but """+prefix+"""AF not defined'
        #endif
    #else
        #ifdef """+prefix+"""AF
            #error '"""+prefix+"""AF defined, but MODE != GPIO_MODE_ALTERNATE'
        #endif
    #endif
    #if ("""+prefix+"""MODE == GPIO_MODE_OUTPUT)
        #ifndef """+prefix+"""DEFAULT_STATE
            #warning '"""+prefix+"""MODE is OUTPUT, but no DEFAULT_STATE defined'
        #endif
    #endif
    #ifndef """+prefix+"""DEFAULT_STATE
        #define """+prefix+"""DEFAULT_STATE 0
    #endif
    #ifndef """+prefix+"""AF
        #define """+prefix+"""AF GPIO_AF0
    #endif
    #ifndef """+prefix+"""OTYPE
        #define """+prefix+"""OTYPE GPIO_OTYPE_PP
    #endif
    #ifndef """+prefix+"""PUPD
        #define """+prefix+"""PUPD GPIO_PUPD_NONE
    #endif
    #ifndef """+prefix+"""OSPEED
        #define """+prefix+"""OSPEED GPIO_OSPEED_LOW
    #endif
#endif
"""
        f.write(pinconfig)

f.write("/*END of insane macros, let's do some C...*/")

f.write("""
void gpio_init(void)
{
    bit_set(RCC->"""+CLK_EN_REG+""", \\\n""")

#enable clocks
for port in PORTS:
    f.write("                RCC_"+CLK_EN_REG+"_GPIO"+port+"EN |\\\n")
f.write("                0);\n\n")

#load configs to registers

for port in PORTS:
    f.write("/*GPIO{}*/\n".format(port))
    f.write("    GPIO{}->ODR = \\\n".format(port, port))
    for pin in range(PINS):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}DEFAULT_STATE  << {} |\\\n".format(prefix, pin,)) #omg, no ..._Pos macros defined in header file from ST!!
    f.write("                    0;\n\n")

    f.write("    GPIO{}->PUPDR = \\\n".format(port, port))
    for pin in range(PINS):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}PUPD  << GPIO_PUPDR_PUPDR{}_Pos |\\\n".format(prefix, pin))
    f.write("                    0;\n\n")

    f.write("    GPIO{}->MODER = \\\n".format(port, port))
    for pin in range(PINS):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}MODE  << GPIO_MODER_MODER{}_Pos |\\\n".format(prefix, pin,))
    f.write("                    0;\n\n")

    f.write("    GPIO{}->AFR[0] = \\\n".format(port, port))
    for pin in range(PINS//2):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}AF  << GPIO_AFRL_AFRL{}_Pos |\\\n".format(prefix, pin))
    f.write("                    0;\n\n")

    f.write("    GPIO{}->AFR[1] = \\\n".format(port, port))
    for pin in range(PINS//2, PINS):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}AF  << GPIO_AFRH_AFRH{}_Pos |\\\n".format(prefix, pin-8))#no, they just can't preserve numbering from 0 to 15...
    f.write("                    0;\n\n")

    f.write("    GPIO{}->OTYPER = \\\n".format(port, port))
    for pin in range(PINS):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}OTYPE  << {} |\\\n".format(prefix, pin,)) #omg, no ..._Pos macros defined in header file from ST!!
    f.write("                    0;\n\n")

    f.write("    GPIO{}->OSPEEDR = \\\n".format(port, port))
    for pin in range(PINS):
        prefix="P{}_{}_".format(port,pin)
        f.write("                    {}OSPEED  << GPIO_OSPEEDER_OSPEEDR{}_Pos |\\\n".format(prefix, pin))
    f.write("                    0;\n\n")


f.write("}\n")


f.write(FOOTER)
f.close()

print("Done!")
