#ifndef _SDRAM_LIB
	#define _SDRAM_LIB
	#include "config.h"

	void sdram_init(void);
	bool sdram_check(uint32_t base_addr);

#endif