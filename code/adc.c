#include "device.h"
#include "adc.h"
#include "misc.h"
#include "debug.h"

#ifdef DEBUG_ADC
	#pragma message "ADC debug enabled!"
	#include "debug_enable.h"
#endif

#define ADC_SEQ_SMPR	7

uint16_t adc_buffer[(ADC_SEQUENCE_LENGTH)*(ADC_OVERSAMPLE)];

uint16_t adc_avg_buffer_ex(uint16_t *data, uint8_t index, uint8_t step, uint8_t samples)
{
	uint32_t buffer=0;
	for(uint8_t idx=0; idx<samples; idx++)
	{
		buffer += data[index+idx*step];
	}
	return buffer/samples;
}

uint16_t adc_avg(uint8_t index)
{
	return adc_avg_buffer_ex(adc_buffer, index, ADC_SEQUENCE_LENGTH, ADC_OVERSAMPLE);
}

void adc_init(void)
{
	DEBUG_CRITICAL_STR("ADC init\n");

	DMA_Stream_TypeDef *stream=DMA2_Stream0 + ADC_DMA_STREAM;
	stream->PAR  = (uint32_t)&ADC1->DR;
	stream->M0AR = (uint32_t)adc_buffer;
	stream->NDTR = (ADC_SEQUENCE_LENGTH)*(ADC_OVERSAMPLE);
	stream->CR   =	ADC_DMA_CHANNEL<<DMA_SxCR_CHSEL_Pos |
					BIT(DMA_SxCR_MINC_Pos) |
					BIT(DMA_SxCR_CIRC_Pos) |
					BIT(DMA_SxCR_EN_Pos)|
					1<<DMA_SxCR_PSIZE_Pos|
					1<<DMA_SxCR_MSIZE_Pos;

	const uint8_t sequence[16]={ADC_SEQUENCE};

	ADC1->SQR3 =	sequence[0]<<ADC_SQR3_SQ1_Pos|
					sequence[1]<<ADC_SQR3_SQ2_Pos|
					sequence[2]<<ADC_SQR3_SQ3_Pos|
					sequence[3]<<ADC_SQR3_SQ4_Pos|
					sequence[4]<<ADC_SQR3_SQ5_Pos|
					sequence[5]<<ADC_SQR3_SQ6_Pos;
	ADC1->SQR2 =	sequence[6]<<ADC_SQR2_SQ7_Pos|
					sequence[7]<<ADC_SQR2_SQ8_Pos|
					sequence[8]<<ADC_SQR2_SQ9_Pos|
					sequence[9]<<ADC_SQR2_SQ10_Pos|
					sequence[10]<<ADC_SQR2_SQ11_Pos |
					sequence[11]<<ADC_SQR2_SQ12_Pos;
	ADC1->SQR1 =	sequence[12]<<ADC_SQR1_SQ13_Pos|
					sequence[13]<<ADC_SQR1_SQ14_Pos|
					sequence[14]<<ADC_SQR1_SQ15_Pos|
					sequence[15]<<ADC_SQR1_SQ16_Pos|
					((ADC_SEQUENCE_LENGTH)-1)<<ADC_SQR1_L_Pos;
	//maximum sample time, no haste...
	ADC1->SMPR1 =	0xFFFFFFFF;
	ADC1->SMPR2 =	0xFFFFFFFF;

	ADC->CCR = ADC_CCR_TSVREFE | ADC_CCR_VBATE | 1<<ADC_CCR_ADCPRE_Pos;
	ADC1->CR1 =	ADC_CR1_SCAN;//scan mode
	ADC1->CR2 = ADC_CR2_DMA | ADC_CR2_DDS | ADC_CR2_ADON;
}