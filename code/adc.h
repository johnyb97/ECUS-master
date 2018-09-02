#ifndef _ADC_LIB
	#define _ADC_LIB
	#include "config.h"
	#include <inttypes.h>
	#include "misc.h"
	#include "device.h"
	// #include "uart.h"

	#if (ADC_SEQUENCE_LENGTH > 16)
		#error "ADC_SEQUENCE too long, scan mode supports 16 channel at MAX!"
	#endif

	void adc_init(void);
	uint16_t adc_avg(uint8_t index);

	static inline void adc_trigger(void)
	{
		bit_set(ADC1->CR2, ADC_CR2_SWSTART);	
	}

#endif