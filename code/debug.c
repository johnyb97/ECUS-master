#include "debug.h"


/*!
 * \brief Initialize the SWO trace port for debug message printing
 * \param portBits Port bit mask to be configured
 * \param cpuCoreFreqHz CPU core clock frequency in Hz
 */
void SWO_Init(void) 
{

	/* Select the SWO interface */
	DBGMCU->CR &= DBGMCU_CR_TRACE_MODE_Msk;
	
	/* Enable the TRACE interface */
	DBGMCU->CR |= DBGMCU_CR_TRACE_IOEN;
}


void debug_init(void)
{
	SWO_Init();
}

void debug_print_ch(const uint8_t data)
{
	// SWO_PrintChar(data, 0);
	ITM_SendChar(data);
}

void debug_print(const uint8_t *data)
{
	while (*data!='\0') {
		debug_print_ch(*data++);
	}
}