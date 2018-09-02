#include "sdram.h"
#include "misc.h"
#include "gpio.h"
#include <stdint.h>
#include "debug.h"

#include "debug_enable.h"

#define FMC FMC_Bank5_6

static inline void sdram_wait_for_complete(void)
{
	while(bit_get(FMC->SDSR, FMC_SDSR_BUSY_Msk) == FMC_SDSR_BUSY)
		NOP;
}

uint32_t PRNG(uint32_t *nSeed)
{
    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // very hard for someone to predict what the next number is
    // going to be from the previous one.
    *nSeed = (8253729 * *nSeed + 2396403); 

    // Take the seed and return a value between 0 and 32767
    return *nSeed  % INT32_MAX;
}


#define FMC_SDCMR_MODE_NORMAL_MODE					(0<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_CLOCK_CONFIGURATION_ENABLE	(1<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_ALL_BANK_PRECHARGE			(2<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_AUTO_REFRESH					(3<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_LOAD_MODE_REGISTER			(4<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_SELF_REFRESH					(5<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_POWER_DOWN					(6<<FMC_SDCMR_MODE_Pos)
#define FMC_SDCMR_MODE_RESERVED						(7<<FMC_SDCMR_MODE_Pos)

/**
  * @brief  FMC SDRAM Mode definition register defines
  */
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000) 
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)      

void sdram_init(void)
{

  /* GPIO configuration for FMC SDRAM bank */
  // SDRAM_GPIOConfig();

  /* Enable FMC clock */
  // RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FMC, ENABLE);


/* FMC Configuration ---------------------------------------------------------*/
/* FMC SDRAM Bank configuration */
  /* Timing configuration for 90 Mhz of SD clock frequency (180Mhz/2) */
  // /* TMRD: 2 Clock cycles */
  // FMC_SDRAMTimingInitStructure.FMC_LoadToActiveDelay    = 2;
  // /* TXSR: min=70ns (7x11.11ns) */
  // FMC_SDRAMTimingInitStructure.FMC_ExitSelfRefreshDelay = 7;
  // /* TRAS: min=42ns (4x11.11ns) max=120k (ns) */
  // FMC_SDRAMTimingInitStructure.FMC_SelfRefreshTime      = 4;
  // /* TRC:  min=70 (7x11.11ns) */
  // FMC_SDRAMTimingInitStructure.FMC_RowCycleDelay        = 7;
  // /* TWR:  min=1+ 7ns (1+1x11.11ns) */
  // FMC_SDRAMTimingInitStructure.FMC_WriteRecoveryTime    = 2;
  // /* TRP:  20ns => 2x11.11ns */
  // FMC_SDRAMTimingInitStructure.FMC_RPDelay              = 2;
  // /* TRCD: 20ns => 2x11.11ns */
  // FMC_SDRAMTimingInitStructure.FMC_RCDDelay             = 2;


// 1
	FMC->SDCR[0] = \
		(1<<FMC_SDCR1_RPIPE_Pos)|
		(0<<FMC_SDCR1_RBURST_Pos)|
		(2<<FMC_SDCR1_SDCLK_Pos)|
		(0<<FMC_SDCR1_WP_Pos)|
		(3<<FMC_SDCR1_CAS_Pos)|
		(1<<FMC_SDCR1_NB_Pos)|
		(2<<FMC_SDCR1_MWID_Pos)|
		(1<<FMC_SDCR1_NR_Pos)|
		(0<<FMC_SDCR1_NC_Pos);

// 2
	FMC->SDTR[0] = \
  		(1<<FMC_SDTR1_TMRD_Pos)|
		(6<<FMC_SDTR1_TXSR_Pos)|
		(4<<FMC_SDTR1_TRAS_Pos)|
		(6<<FMC_SDTR1_TRC_Pos)|
		(1<<FMC_SDTR1_TWR_Pos)|
		(1<<FMC_SDTR1_TRP_Pos)|
		(1<<FMC_SDTR1_TRCD_Pos);


	sdram_wait_for_complete();

// 3 start clock delivery
	FMC->SDCMR =  \
		(FMC_SDCMR_MODE_CLOCK_CONFIGURATION_ENABLE)|
		(1<<FMC_SDCMR_CTB1_Pos)|
		(1<<FMC_SDCMR_NRFS_Pos)|
		(0<<FMC_SDCMR_MRD_Pos);
// 4
	delay_ms(1);

	sdram_wait_for_complete();

// 5 precharge all cmd
	FMC->SDCMR = \
		(FMC_SDCMR_MODE_ALL_BANK_PRECHARGE)|
		(1<<FMC_SDCMR_CTB1_Pos)|
		(1<<FMC_SDCMR_NRFS_Pos)|
		(0<<FMC_SDCMR_MRD_Pos);
	sdram_wait_for_complete();

// 6 issue auto refresh
// IS42S16400J DSH says at least 2, previous project used 4, so stick to 4
	FMC->SDCMR = \
		(FMC_SDCMR_MODE_AUTO_REFRESH)|
		(1<<FMC_SDCMR_CTB1_Pos)|
		(4<<FMC_SDCMR_NRFS_Pos)|
		(0<<FMC_SDCMR_MRD_Pos);
	sdram_wait_for_complete();

// 7 Configure RAMs registers
	{
  		uint32_t ramreg = (uint32_t)\
			SDRAM_MODEREG_BURST_LENGTH_2|
			SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL|
			SDRAM_MODEREG_CAS_LATENCY_3|
			SDRAM_MODEREG_OPERATING_MODE_STANDARD|
			SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

		FMC->SDCMR = \
			(FMC_SDCMR_MODE_LOAD_MODE_REGISTER)|
			(1<<FMC_SDCMR_CTB1_Pos)|
			(1<<FMC_SDCMR_NRFS_Pos)|
			(ramreg<<FMC_SDCMR_MRD_Pos);
	}
	sdram_wait_for_complete();

// 8 program refresh rate
	FMC->SDRTR = (1542<<FMC_SDRTR_COUNT_Pos);

	sdram_wait_for_complete();

	FMC->SDCMR = \
		(FMC_SDCMR_MODE_NORMAL_MODE)|
		(1<<FMC_SDCMR_CTB1_Pos)|
		(1<<FMC_SDCMR_NRFS_Pos)|
		(0<<FMC_SDCMR_MRD_Pos);

	sdram_wait_for_complete();
}
bool sdram_check(uint32_t base_addr)
{
	DEBUG_STR("SDRAM check started...\n");
	uint32_t idx;
	uint32_t nSeed=5323;
	uint32_t *SDRAM = (uint32_t*)base_addr;

	for(idx=0; idx<(SDRAM_SIZE/sizeof(*SDRAM)); idx++)
	{
		SDRAM[idx]=PRNG(&nSeed);
	}

	DEBUG_STR("\twriting...\n");

	nSeed=5323;
	for(idx=0; idx<(SDRAM_SIZE/sizeof(*SDRAM)); idx++)
	{
		if(SDRAM[idx]!=PRNG(&nSeed))
		{
			DEBUG_STR("\tcheck failed!\n");		
			return false;
		}
	}
	DEBUG_STR("\tcheck passed!\n");
	return true;
}