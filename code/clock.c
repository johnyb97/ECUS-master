#include "clock.h"
#include "misc.h"
#include "gpio.h"



#ifdef BUILD_DEBUG
	#pragma message show_value(F_VCO)
	#pragma message show_value(_F_VCO_MIN)
	#pragma message show_value(_F_VCO_MAX)
#endif

#ifdef BUILD_DEBUG
	#pragma message show_value(F_HCLK)
	#pragma message show_value(_F_HCLK_MAX)
#endif

#ifdef BUILD_DEBUG
	#pragma message show_value(F_APB1)
	#pragma message show_value(_F_APB1_MAX)
#endif

#ifdef BUILD_DEBUG
	#pragma message show_value(F_APB2)
	#pragma message show_value(_F_APB2_MAX)
#endif

#ifndef F_XTAL
	#error "F_XTAL must be defined"
#endif

#ifndef PLLM
	#error "PLLM must be defined"
#endif

#ifndef PLLN
	#error "PLLN must be defined"
#endif

#ifndef PLLP
	#error "PLLP must be defined"
#endif

#ifndef PPRE1
	#error "PPRE1 must be defined"
#endif

#ifndef PPRE2
	#error "PPRE2 must be defined"
#endif

#if PLLM <= 1
	#error "PLLM must be >1"
#endif

#if PLLN <= 1
	#error "PLLM must be >1"
#endif

#ifndef FLASH_WS
	#error "FLASH_WS must be defined"
#endif

#if PLLP!=2 && PLLP!=4 && PLLP!=6 && PLLP!=8
	#error "PLLP must be 2,4,6 or 8"
#endif

#if PPRE1!=1 && PPRE1!=2 && PPRE1!=4 && PPRE1!=8 && PPRE1!=16
	#error "PPRE1 must be 1,2,4,8 or 16"
#endif

#if PPRE2!=1 && PPRE2!=2 && PPRE2!=4 && PPRE2!=8 && PPRE2!=16
	#error "PPRE2 must be 1,2,4,8 or 16"
#endif

#define _1MHZ		1000000UL

#if F_VCO<(50*_1MHZ) || F_VCO>(432*_1MHZ)
	#error "VCO frequency is out of <50; 432> MHz, increase PLLM or decrease PLLN"
#endif

#if F_HCLK>(200UL*_1MHZ)
	#error "F_HCLK frequency is above 432 MHz, increase PLLM, decrease PLLN or increase PLLP"
#endif

#if F_APB1>(54UL*_1MHZ)
	#error "F_APB1 frequency is above 54 MHz, increase PPRE1 or decrease system clock"
#endif

#if F_APB2>(108UL*_1MHZ)
	#error "F_APB2 frequency is above 108 MHz, increase PPRE2 or decrease system clock"
#endif

#if PPRE1 == 1
	#define PPRE1_RAW	0
#elif PPRE1 == 2
	#define PPRE1_RAW	4
#elif PPRE1 == 4
	#define PPRE1_RAW	5
#elif PPRE1 == 8
	#define PPRE1_RAW	6
#elif PPRE1 == 16
	#define PPRE1_RAW	7
#else
	#error "can't convert PPRE1 to register value!"
#endif

#if PPRE2 == 1
	#define PPRE2_RAW	0
#elif PPRE2 == 2
	#define PPRE2_RAW	4
#elif PPRE2 == 4
	#define PPRE2_RAW	5
#elif PPRE2 == 8
	#define PPRE2_RAW	6
#elif PPRE2 == 16
	#define PPRE2_RAW	7
#else
	#error "can't convert PPRE1 to register value!"
#endif

status_t clock_init(void)
{
	bit_set(RCC->APB1ENR,RCC_APB1ENR_PWREN);
	// bit_set(RCC->CR, RCC_CR_HSION);//enable HSI
	// while(bit_get(RCC->CR, RCC_CR_HSIRDY)==0)//wat for HSI to start
	//  	NOP;


	bit_set(RCC->CR, RCC_CR_HSEON);//start HSE
	while(bit_get(RCC->CR, RCC_CR_HSERDY)==0)//wat for HSE to start
	 	NOP;

	// bit_clr(RCC->CR, RCC_CR_PLLON);//disable PLL

	// 8MHZ xtal
	//VCO IN must be 1~2MHz but, 2 MHz preferred due to lower PLL jitter
	//-> PLLM=4
	//VCO output muste be within 100 and 432MHz
	//PLL output must be 216MHz or less
	//8/PLLM*PLLN/PLLP
	//tgt ~200MHz -> 8/4*200/2 = 200MHz

	RCC->PLLCFGR = ((PLLM)<<RCC_PLLCFGR_PLLM_Pos) | ((PLLN)<<RCC_PLLCFGR_PLLN_Pos) | (((PLLP)/2-1)<<RCC_PLLCFGR_PLLP_Pos) | RCC_PLLCFGR_PLLSRC_HSE;//set PLL
	bit_set(RCC->CR, RCC_CR_PLLON);//enable PLL


	bit_set(PWR->CR1, PWR_CR1_ODEN);//enable overdrive
	while(bit_get(PWR->CSR1, PWR_CSR1_ODRDY_Msk)==0)//wat for Overdrive ready
	 	NOP;

	bit_set(PWR->CR1, PWR_CR1_ODSWEN);//switch regulator to overdrive mode
	while(bit_get(PWR->CSR1, PWR_CSR1_ODSWRDY)==0)//wat for overdrive switch to complete
	 	NOP;


	bit_set(FLASH->ACR, (FLASH_WS)<<FLASH_ACR_LATENCY_Pos | FLASH_ACR_ARTEN );//7WS for flash at 3.3V and 200MHz

	bit_set(RCC->CFGR, ((PPRE1_RAW)<<RCC_CFGR_PPRE1_Pos) | ((PPRE2_RAW)<<RCC_CFGR_PPRE2_Pos) );


	while(bit_get(RCC->CR, RCC_CR_PLLRDY)==0)//wat for PLL to lock
		NOP;

	bit_mod(RCC->CFGR, RCC_CFGR_SW_Msk, RCC_CFGR_SW_PLL); //switch to PLL clocks

	if(bit_get(RCC->CFGR, RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL)
		return STAT_ERR_HW;

	// put PLL/4 on MCO1 (BTN B3)
	bit_set(RCC->CFGR, (3<<RCC_CFGR_MCO1_Pos) | (6<<RCC_CFGR_MCO1PRE_Pos));


	//PLL for LCD
	RCC->PLLSAICFGR = (2<<RCC_PLLSAICFGR_PLLSAIR_Pos) | (2<<RCC_PLLSAICFGR_PLLSAIQ_Pos) | (2<<RCC_PLLSAICFGR_PLLSAIP_Pos) | (60<<RCC_PLLSAICFGR_PLLSAIN_Pos);
	// RCC->DKCFGR1 = 0;
	bit_set(RCC->CR, RCC_CR_PLLSAION);
	while(bit_get(RCC->CR, RCC_CR_PLLSAIRDY)==0)//wat for PLL to lock
		NOP;

	return STAT_OK;
}