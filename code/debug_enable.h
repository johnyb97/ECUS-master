#ifndef _DEBUG_ENABLE
#define _DEBUG_ENABLE
    #undef  DEBUG_STR
	#undef  DEBUG_NL
	#undef  DEBUG_NUM
	#undef  DEBUG_NUM_EX
	#undef  DEBUG_ADDR
	#undef  DEBUG_CH

	#define DEBUG_STR(STRING)					DEBUG_CRITICAL_STR(STRING)
	#define DEBUG_NL()							DEBUG_CRITICAL_NL()
	#define DEBUG_NUM(NUM,DIGITS)				DEBUG_CRITICAL_NUM(NUM,DIGITS)
	#define DEBUG_NUM_EX(NUM,DIGITS,FILLER,BASE)		DEBUG_CRITICAL_NUM_EX(NUM,DIGITS,FILLER,BASE)
	#define DEBUG_ADDR(NUM,DIGITS)				DEBUG_CRITICAL_ADDR(NUM,DIGITS)
	#define DEBUG_CH(CH)						DEBUG_CRITICAL_CH(CH)
#endif