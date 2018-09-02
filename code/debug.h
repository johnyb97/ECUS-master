#ifndef _DEBUG_LIB
	#define _DEBUG_LIB

	#include "config.h"
	#include "misc.h"
	#include <string.h>


	// #define _DEBUG_SEND_ARRAY(data_ptr, data_len)	UNUSED(data_ptr);do{}while(0)
	// #define _DEBUG_SEND_BYTE(data) 					do{}while(0)

	void debug_init(void);
	void debug_print_ch(const uint8_t data);
	void debug_print(const uint8_t *data);


	#define DEBUG_INT_STR(STRING)		debug_print((const uint8_t*)STRING)
	#define DEBUG_INT_NL()				debug_print_ch('\n')
	// #define DEBUG_INT_NUM(NUM,DIGITS)	DEBUG_INT_STR(itoa(NUM, DIGITS))
	#define DEBUG_INT_NUM(NUM, DIGITS, FILLER, BASE)	\
		do{ \
			char _b[32];\
			char *_n=itoa_dec_fill_extbuff(_b, NUM, DIGITS, FILLER, 0,BASE);\
			DEBUG_INT_STR(_n);\
		}while(0)
	#define DEBUG_INT_CH(CH)				debug_print_ch(CH)

	#define DEBUG_CRITICAL_STR(STRING)		DEBUG_INT_STR(STRING)
	#define DEBUG_CRITICAL_NL()				DEBUG_INT_CH('\n')
	#define DEBUG_CRITICAL_NUM(NUM,DIGITS)	DEBUG_INT_NUM(NUM,DIGITS,' ',10)
	#define DEBUG_CRITICAL_NUM_EX(NUM,DIGITS,FILLER,BASE)	DEBUG_INT_NUM(NUM,DIGITS,FILLER,BASE)
	#define DEBUG_CRITICAL_ADDR(NUM,DIGITS)	DEBUG_INT_NUM(NUM,DIGITS,'0',16)
	#define DEBUG_CRITICAL_CH(CH)			DEBUG_INT_CH(CH)
	#define DEBUG_EMPTY()					do{}while(0)

	#define DEBUG_STR(STRING)					DEBUG_EMPTY()
	#define DEBUG_NL()							DEBUG_EMPTY()
	#define DEBUG_NUM(NUM,DIGITS)				DEBUG_EMPTY()
	#define DEBUG_NUM_EX(NUM,DIGITS,FILLER,BASE)	DEBUG_EMPTY()
	#define DEBUG_ADDR(NUM,DIGITS)				DEBUG_EMPTY()
	#define DEBUG_CH(CH)						DEBUG_EMPTY()



#endif