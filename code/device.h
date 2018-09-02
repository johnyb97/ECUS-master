#ifndef __DEVICE_INC
	#include "stm32f746xx.h"
	#define __DEVICE_INC

	// #define BITBAND_PERIPH_BASE (PERIPH_BASE+0x02000000UL)

	#if GPIO_BSRR_BS_0 >= (1<<16)
		#define GPIO_BSRR_BS_OFFSET 16
		#define GPIO_BSRR_BR_OFFSET 0
	#else
		#define GPIO_BSRR_BS_OFFSET 0
		#define GPIO_BSRR_BR_OFFSET 16
	#endif

#endif
