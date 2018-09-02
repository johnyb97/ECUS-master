#include "iwdg.h"
#include "debug.h"

// #include "debug_enable.h"

#define IWDG_RESET_KEY		0x0000AAAAul
#define IWDG_UNLOCK_KEY_1	0x0000CCCCul
#define IWDG_UNLOCK_KEY_2	0x00005555ul

void iwdg_reset(void)
{
	IWDG->KR = IWDG_RESET_KEY;
	DEBUG_STR("WDT reset\n");
}

void iwdg_init(void)
{
	DEBUG_CRITICAL_STR("WDT init...\n");
	IWDG->KR = IWDG_UNLOCK_KEY_1;
	IWDG->KR = IWDG_UNLOCK_KEY_2;
	IWDG->PR = 5<<IWDG_PR_PR_Pos;//PSC=128
	IWDG->RLR = 1000;
	while(IWDG->SR != 0)
		NOP;
	DEBUG_CRITICAL_STR("WDT ready!\n");
}
