#ifndef _CONFIG
	#define _CONFIG

	#include <device.h>
	#include <inttypes.h>

	#define memcpy __builtin_memcpy
	// typedef uint16_t size_t;
	#include <stddef.h>
	#include <stdbool.h>

	#include "misc.h"

	//Laggers' VDCU parameters!
	#define VDCU_PARAM_PERIODIC_UPDATE_MS	100
	#define VDCU_PARAM_TIMEOUT_MS			 20
	#define VDCU_PARAM_RETRY_COUNT			  5

	//menu config
	#define MENU_IDLE_TIMEOUT_ms	5000

	// #define BUILD_DEBUG
	// #define DEBUG_CAN

	#define F_SYSTICK		 1000UL

	#define F_XTAL		8000000UL	//HSE crystal freq
	#define PLLM		4			//divide xtal by
	#define PLLN		200			//multiply by
	#define PLLP		2			//divide pll outout by
	#define PPRE1		4			//divide HCLK for APB1
	#define PPRE2		2			//divide HCLK for APB2

	#define FLASH_WS	6			//wait states of flash 180MHz ~ 210MHz -> 6WS


	// #define F_SYSTICK	1000

	#define SDRAM_SIZE			(16UL*1024*1024) //16MiB
	#define SDRAM_BANK_SIZE		(0x400000UL) //4MiB
	#define SDRAM_ADDR_BASE		(0xC0000000UL)
	#define SDRAM_ADDR_BANK(id) (SDRAM_ADDR_BASE+((SDRAM_BANK_SIZE)*(id)))
	#define SDRAM_ADDR_BANK_0	SDRAM_ADDR_BANK(0)
	#define SDRAM_ADDR_BANK_1	SDRAM_ADDR_BANK(1)
	#define SDRAM_ADDR_BANK_2	SDRAM_ADDR_BANK(2)
	#define SDRAM_ADDR_BANK_3	SDRAM_ADDR_BANK(3)
	//en.DM00287603.pdf
	//4.5.3 Optimizing the LTDC framebuffer fetching from SDRAM
	//As the LTDC is performing sequential accesses, it's important that no other masters are doing access into the same SDRAM bank.

	//all ADC inputs that are converted, processing function must be modified accordingly

	//AIN1 - PC4 -IN4
	//AIN2 - PC5 -IN5

	#define ADC_SEQUENCE	14, 15,//MAX 16
	#define ADC_SEQUENCE_LENGTH	2
	#define ADC_OVERSAMPLE	4
	#define ADC_AIN1_INDEX	0 //those are indexes in sequence
	#define ADC_AIN2_INDEX	1

	#define ADC_DMA_CHANNEL		0
	#define ADC_DMA_STREAM		0

	#define CAN_TX_BUFFER_SIZE	64
	#define CAN_RX_BUFFER_SIZE	1024

	//HSYNC ^^^^^^^|_____________________________________
	//DATA  ________________XXXXXXXXXXXXXXXXXXXXXX_______
	//       HSYNC    HFP           WIDTH           HBP

	//HSYNC	1 +
	//HBP	2 ~ 126
	//HFP	2 +
	//HSYNC+HBP+HFP>=4.5us

	//VSYNC	1 ~ 126
	//VBP	1 ~ 126
	//VFP	1 ~ 255

	//ILI reg HBP = HBP+HSYNC	(5)
	//ILI reg VBP = VBP+VSYNC	(20)
	//ILI reg VFP = VFP			(20)

	#define LCD_HSYNC	2
	#define LCD_HBP		3
	#define LCD_HFP		140
	#define LCD_WIDTH	480

	#define LCD_VSYNC	10
	#define LCD_VBP		10
	#define LCD_VFP		10
	#define LCD_HEIGHT	800

	//NUKLEAR CONFIG
	#define NK_INCLUDE_FIXED_TYPES
	// #define NK_INCLUDE_FONT_BAKING
	// #define NK_INCLUDE_DEFAULT_FONT

	//define IRQs priorities (4bits, lower value means highers priority, default 0 - highest)
	//4 bits (0~15)
	//Preempt Priority (2 MSb) and Subpriority (2LSb)
	#define IRQ_PRIORITY(preempt, sub)	((preempt)<<2UL|sub) //little helper
	#define CAN1_RX_IRQ_PRIORITY	IRQ_PRIORITY(0,0)
	#define CAN1_TX_IRQ_PRIORITY	IRQ_PRIORITY(1,0)
	#define LTDC_IRQ_PRIORITY		IRQ_PRIORITY(2,0)

	//SPI
	struct SPI_SLAVE
	{
		SPI_TypeDef *SPI;
		GPIO_TypeDef *PORT;
		const uint8_t pin;
	};
	//configure SPI slaves in config.c
	extern const struct SPI_SLAVE SPI_SLAVE_LIST[];

	#define LCD_SPI	SPI_SLAVE_LIST[0]

	inline static void fault_end(void)
	{
		__disable_irq();
		while(1)
			NOP;
	}
#endif
