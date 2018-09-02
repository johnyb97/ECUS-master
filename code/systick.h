#ifndef _LIB_SYSTICK
	#define _LIB_SYSTICK
	
	#include "config.h"

	extern volatile uint32_t time_from_start;
	static inline uint32_t SysTick_uptime(void)
	{
		return time_from_start;
	};

	void SysTick_init(void(*callback)(uint32_t time));
#endif