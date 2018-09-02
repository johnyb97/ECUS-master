#ifndef _CLOCK_LIB
	#define _CLOCK_LIB

	#include "config.h"
	#include "device.h"

	#define xstr(s) str(s)
	#define str(s) #s
	#define show_value(x) #x " is " xstr(x)

	// #define _MHZ		(1000000UL)

	// #define _CLOCK_F_APB1_MAX	(48*_MHZ)

	// #define _CLOCK_F_HCLK_MAX	(80*_MHZ)


	// #ifdef CLOCK_USE_HSI
	// 	#ifndef CLOCK_F_HSI
	// 		#error CLOCK_F_HSI not defined
	// 	#else
	// 		#define CLOCK_F_OSC CLOCK_F_HSI
	// 	#endif
	// #endif

	// #ifndef CLOCK_PLL_MUL
	// 	#error CLOCK_PLL_MUL not defined
	// #endif

	// #ifndef CLOCK_AHB_PSC
	// 	#error CLOCK_AHB_PSC not defined
	// #endif

	// #ifndef CLOCK_APB1_PSC
	// 	#error CLOCK_APB1_PSC not defined
	// #endif

	#define F_VCO		((F_XTAL)/(PLLM)*(PLLN))
	#define F_HCLK		((F_VCO)/(PLLP))
	#define F_APB1		((F_HCLK)/(PPRE1))
	#define F_APB2		((F_HCLK)/(PPRE2))
	#define F_CPU		(F_HCLK)

	status_t clock_init(void);

#endif