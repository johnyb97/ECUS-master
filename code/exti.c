#include "exti.h"

void(*exti_callback[EXTI_CALLBACK_COUNT])(void);

#define p32_to_ui32(A) (uint32_t)A

static exti_port_t port_to_exti_port(GPIO_TypeDef *port)
{
	switch(p32_to_ui32(port))
	{
		case p32_to_ui32(GPIOA): return EXTI_PORT_A;
		case p32_to_ui32(GPIOB): return EXTI_PORT_B;
		case p32_to_ui32(GPIOC): return EXTI_PORT_C;
		case p32_to_ui32(GPIOD): return EXTI_PORT_D;
		case p32_to_ui32(GPIOE): return EXTI_PORT_E;
		case p32_to_ui32(GPIOF): return EXTI_PORT_F;
		case p32_to_ui32(GPIOG): return EXTI_PORT_G;
		case p32_to_ui32(GPIOH): return EXTI_PORT_H;
		case p32_to_ui32(GPIOI): return EXTI_PORT_I;
		case p32_to_ui32(GPIOJ): return EXTI_PORT_J;
		case p32_to_ui32(GPIOK): return EXTI_PORT_K;
		default:
			return 0;
	}
}

void exti_init(void)
{
	for(uint8_t e=0; e<EXTI_CALLBACK_COUNT; e++)
		exti_callback[e]=NULL;

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

status_t exti_register_callback(uint8_t exti, GPIO_TypeDef *port, bool rising, bool falling, void(*callback)(void))
{
	if(exti>=EXTI_CALLBACK_COUNT)
	{
		return STAT_ERR_OUT_OF_RANGE;
	}

	exti_port_t exti_port = port_to_exti_port(port);

	if(exti<EXTI_CALLBACK_PINS)//if exti number is 0 to 15, select port
	{
		uint8_t exti_bank=exti/4;
		uint8_t exti_idx=exti%4;	
		bit_mod(SYSCFG->EXTICR[exti_bank], 0xFul<<(exti_idx*4), exti_port<<(exti_idx*4));//select port
	}

	if(rising)
		bit_set(EXTI->RTSR, BIT(exti));
	else
		bit_clr(EXTI->RTSR, BIT(exti));

	if(falling)
		bit_set(EXTI->FTSR, BIT(exti));
	else
		bit_clr(EXTI->FTSR, BIT(exti));

	exti_callback[exti]=callback;
	
	bit_set(EXTI->IMR,BIT(exti));//enable

	return STAT_OK;
}

status_t exti_reset(uint8_t exti)
{
	if(exti>=EXTI_CALLBACK_COUNT)
		return STAT_ERR_OUT_OF_RANGE;
	
	bit_clr(EXTI->IMR,BIT(exti));//disable

	// exti_callback[exti]=callback;
	return STAT_OK;
}

void EXTI0_IRQHandler(void)
{
	EXTI->PR = EXTI_PR_PR0;
	exti_call_callback(0);
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR = EXTI_PR_PR1;
	exti_call_callback(1);
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR = EXTI_PR_PR2;
	exti_call_callback(2);
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR = EXTI_PR_PR3;
	exti_call_callback(3);
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR = EXTI_PR_PR4;
	exti_call_callback(4);
}

void EXTI9_5_IRQHandler(void)
{
	for(uint8_t e_num=5; e_num<10; e_num++)
	{
		if(bit_get(EXTI->PR,BIT(EXTI_PR_PR0_Pos+e_num)))
		{
			EXTI->PR = BIT(EXTI_PR_PR0_Pos+e_num);
			exti_call_callback(e_num);
		}
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(bit_get(EXTI->PR,BIT(EXTI_PR_PR0_Pos+15)))
	{
		EXTI->PR = BIT(EXTI_PR_PR0_Pos+15);
		exti_call_callback(15);
	}

	for(uint8_t e_num=10; e_num<16; e_num++)
	{
		if(bit_get(EXTI->PR,BIT(EXTI_PR_PR0_Pos+e_num)))
		{
			EXTI->PR = BIT(EXTI_PR_PR0_Pos+e_num);
			exti_call_callback(e_num);
		}
	}
}