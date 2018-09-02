// Copyright (c) 2017 Patrik Bachan
//
// GNU GENERAL PUBLIC LICENSE
//    Version 3, 29 June 2007
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __MISC_LIB
	#define __MISC_LIB

	#include <inttypes.h>
	#include <stddef.h>
	#include <stdbool.h>

	// workaround for linter, IDK why clang ignores <stdboo.h> include
	// #ifndef bool
	// 	#define _LOCAL_BOOL_USED
	// 	typedef enum { false, true } bool;
	// #endif

	#define DO_PRAGMA(x) _Pragma (#x)
	#define TODO(x) DO_PRAGMA(message ("TODO - " #x))

	#define UNUSED(x)	(void)(x)

	#define ASCII_CR	'\r'
	#define ASCII_LF	'\n'

	//for build time debug
	#define STR_HELPER(x) #x
	#define STR(x) STR_HELPER(x)

	#define uabs(x)  ( ( (x) < 0) ? -(x) : (x) )

	//global macros for bitwise manipulation
	#define bit_get(p,m) ((p) & (m))
	#define bit_set(p,m) ((p) |= (m))
	#define bit_clr(p,m) ((p) &= ~(m))
	#define bit_flip(p,m) ((p) ^= (m))
	#define bit_con(c,p,m) (c ? bit_set(p,m) : bit_clr(p,m)) //macro for conditional bit set/clr
	#define bit_mod(p,m,b) ((p) = ((p)&~(m))|(b) )//mask bits, then orr some
	#define BIT(x) (0x1UL << (x))

	//this is epic idea... http://stackoverflow.com/a/7919546
	#define FILL_BITS_FROM_LSB(bits) ((1<<(bits))-1)
	#define FILL_BITS_FROM_MSB(bits) (~((0x80>>((bits)-1))-1)) //meh, you get it?

	//simple NOP, belongs to empty loops etc.
	#define NOP __asm__("NOP");

	#define array_length(A) sizeof(A)/sizeof(A[0])

	#ifndef NULL
		#define NULL ((void *)0)
	#endif

	#define BUFF_SIZE		32

	#define MIN(A,B)	((A)<(B)?(A):(B))
	#define MAX(A,B)	((A)>(B)?(A):(B))

	#define BYTE_SPLIT(a)	((a)>>8),((a)&0xFF)

	#define BYTE_EXTRACT(src, id)	(((uint8_t*)&src)[id])

	#define CONVERT_FROM_BE_2B(data)			__REVSH(data)
	#define CONVERT_FROM_BE_2B_INPLACE(data)	data=CONVERT_FROM_BE_2B(data)

	#define CONVERT_FROM_BE_4B(data)			__REV(data)
	#define CONVERT_FROM_BE_4B_INPLACE(data)	data=CONVERT_FROM_BE_4B(data)

	#define CONVERT_FROM_LE_2B(data)			(data)
	#define CONVERT_FROM_LE_2B_INPLACE(data)	do{}while(0)

	#define CONVERT_FROM_LE_4B(data)			(data)
	#define CONVERT_FROM_LE_4B_INPLACE(data)	do{}while(0)



	//atomic blocks macros
	//details here: https://mcuoneclipse.com/2014/01/26/entercritical-and-exitcritical-why-things-are-failing-badly/

	#ifndef __ASM_WORKAROUND__
	#define CpuCriticalVar()  uint8_t cpuSR

	#define CpuEnterCritical()				\
	do{										\
		asm (								\
		"MRS   R0, PRIMASK\n\t"				\
		"CPSID I\n\t"						\
		"STRB R0, %[output]"				\
		: [output] "=m" (cpuSR) :: "r0");	\
	} while(0)

	#define CpuExitCritical()				\
	do{										\
		asm (								\
		"ldrb r0, %[input]\n\t"				\
		"msr PRIMASK,r0;\n\t"				\
		::[input] "m" (cpuSR) : "r0");		\
	} while(0)

	//custom macro
	#define CpuCriticalBlock(code)			\
	do{										\
		CpuCriticalVar();					\
		CpuEnterCritical();					\
		code							\
		CpuExitCritical();					\
	}while(0)
	#else
		#warning "WRONG macros used!!!!!"
		#define CpuCriticalVar()		do{}while(0)
		#define CpuEnterCritical()		do{}while(0)
		#define CpuExitCritical()		do{}while(0)
		#define CpuCriticalBlock(code)	do{}while(0)
	#endif

uint32_t reduce(uint32_t value, uint8_t decrease);
// char* stoa(const char *str);
// char* ctoa(char c);

extern char char_buffer[BUFF_SIZE];

char *itoa_dec_fill_append(char *output, int32_t val, int32_t min, char filler, uint8_t decimals, uint8_t base);
#define itoa_dec_append(output, val, min, decimals) itoa_dec_fill_append(output, val, min, ' ', decimals, 10)
char *itoa_dec_fill_extbuff(char *buffer, int32_t val, int32_t min, char filler, uint8_t decimals, uint8_t base);
#define itoa_dec_fill(val, min, filler, decimals) itoa_dec_fill_extbuff(char_buffer, val, min, filler, decimals, 10)
#define itoa_fill(val, min, filler) itoa_dec_fill(val, min, filler, 0)
#define itoa_dec(val, min, decimals) itoa_dec_fill(val, min, ' ', decimals)
#define itoa(val, min) itoa_dec_fill(val, min, ' ', 0)
char* ftoa(char *output, float val, uint8_t min_length, uint8_t decimals, char filler);
// int32_t atoi(char *start);
void delay_us(uint16_t delay);
void delay_ms(uint16_t delay);
void delay(uint16_t delay);
uint8_t str_match(uint8_t *A, uint8_t *B, uint8_t size);
void dummy_assert(void *arg);
// uint8_t wait_timeout(volatile uint8_t *port, uint8_t mask, uint8_t timeout, uint8_t high);
// uint8_t wait_timeout_simple(volatile uint8_t *port, uint8_t mask);

#define max(a, b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a > _b ? _a : _b; })

#define min(a, b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a < _b ? _a : _b; })

static inline uint16_t crop_ui16(uint16_t val, uint16_t min, uint16_t max)
{
	if (val < min)
		return min;
	if (val > max)
		return max;
	return val;
	};

	static inline int16_t crop_i16(int16_t val,  int16_t min, int16_t max)
	{
		if(val<min)
			return min;
		if(val>max)
			return max;
		return val;
	};

	static inline int32_t crop_i32(int32_t val,  int32_t min, int32_t max)
	{
		if(val<min)
			return min;
		if(val>max)
			return max;
		return val;
	};

	static inline int32_t linear_aproximation(int32_t x, int32_t x0, int32_t y0, int32_t x1, int32_t y1)
	{
		if(x1==x0)//prevent division by 0
			return 0;

		return (x-x0)*(y1-y0)/(x1-x0) + y0;
	};

	static inline uint8_t count_orders(int32_t number)
	{
		uint8_t order=0;
		while(uabs(number)>=10)
		{
			order++;
			number/=10;
		}
		return order;
	}

	static inline int32_t divRoundClosest(const int32_t n, const int32_t d)
	{
		return ((n < 0) ^ (d < 0)) ? ((n - d/2)/d) : ((n + d/2)/d);
	}

	static inline uint32_t decadic_multiplier(uint8_t order)
	{
		float mul=1;
		for(; order>0; order--)
			mul*=10;
		return mul;
	}

	//for fun...
	union anything
	{
		uint8_t		ui8;
		int8_t		 i8;
		uint16_t	ui16;
		int16_t		 i16;
		uint32_t	ui32;
		int32_t		 i32;

		uint8_t		*ui8p;
		int8_t		 *i8p;
		uint16_t	*ui16p;
		int16_t		 *i16p;
		uint32_t	*ui32p;
		int32_t		 *i32p;
		void		*voidp;

		struct
		{
			uint16_t a;
			uint16_t b;
		}u16_pair;
	};

	struct fixed_point
	{
		int16_t number;
		uint8_t decimals;
	};

	typedef struct array_info
	{
		void *ptr;
		size_t size;
	} array_info;



	typedef enum {
		STAT_ERR_HW = -127,
		STAT_ERR_NULL_ACCESS,
		STAT_ERR_DATA_INTEGRITY,
		STAT_ERR_BUSY,
		STAT_ERR_TIMEOUT,
		STAT_ERR_NOT_FOUND,
		STAT_ERR_NOT_INITIALIZED,
		STAT_ERR_NOT_STARTED,
		STAT_ERR_NOT_FINISHED,
		STAT_ERR_NO_RESPONSE,
		STAT_ERR_OUT_OF_RANGE,
		STAT_ERR_UNDERFLOW,
		STAT_ERR_OVERFLOW,
		STAT_ERR_LENGTH_MISMATCH,
		STAT_OK = 0,
	} status_t;




#endif
