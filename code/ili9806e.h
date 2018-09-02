#ifndef _ili9806e_LIB
	#define _ili9806e_LIB
	#include "config.h"
	#include "misc.h"

	#define CMD_RDEXTCSPI		     0xFE // (Read EXTC command In SPI) Write                                	/ st EXT_SP 1 Parameter Wr EXT_SPI_CNT[6:0] 00h I_R_EN
	#define CMD_ENEXTC	 	         0xFF // (EXTC command set enable register) Write
		// 1st Parameter Wr FFh
		// 2nd Parameter Wr 98h
		// 3rd Parameter Wr 06h
		// 4th Parameter Wr 04h
		// 5th Parameter Rd-Wr PAGE[7:0] 00h

	#define CMD_P0_NOP	             0x00 // (No Operation) Write
	#define CMD_P0_SWRESET	         0x01 // (Software Reset) Write
	#define CMD_P0_RDNUMED	         0x05 // (Read Number of the Errors on DSI) Write 	                          / st 1 Parameter Rd P [7:0] XXh
	#define CMD_P0_RDDPM	         0x0A // (Read Display Power Mode) Write 				                      / st 1 Parameter Rd BSTON	0 0 SLPOUT NORON DISON 0 0 XXh
	#define CMD_P0_RDDMADCTL	     0x0B // (Read Display MADCTL) Write 				                          / st 1 Parameter Rd 0		0 0 0 BGR 0 SS GS XXh
	#define CMD_P0_RDDCOLMOD	     0x0C // (Read Display COLMOD ) Write 			                        	  / st 1 Parameter Rd 0 	DPI [2:0] 0 0 0 0 XXh
	#define CMD_P0_RDDIM	         0x0D // (Read Display Image Mode) Write 				                      / st 1 Parameter Rd 0 	0 INVON ALLPON ALLPOFF GCS [2:0] XXh
	#define CMD_P0_RDDSM	         0x0E // (Read Display Signal Mode) Write 			                          / st 1 Parameter Rd TEON 	0 HSON VSON PCLKON DEON 0 EODSI XXh
	#define CMD_P0_RDDSDR	         0x0F // (Read Display Self-Diagnostic Result) Write                          / st 1 Parameter Rd REGLD	FUNDT 0 0 0 0 0 0 XXh
	#define CMD_P0_SLPIN	         0x10 // (Sleep In) Write
	#define CMD_P0_SLPOUT	         0x11 // (Sleep Out) Write
	#define CMD_P0_NORON	         0x13 // (Normal Display Mode On) Write
	#define CMD_P0_INVOFF	         0x20 // (Display Inversion Off) Write
	#define CMD_P0_INVON	         0x21 // (Display Inversion ON) Write
	#define CMD_P0_ALLPOFF	         0x22 // (All pixels off) Write
	#define CMD_P0_ALLPON	         0x23 // (All pixels on) Write
	#define CMD_P0_GAMSET	         0x26 // (Gamma Set) Write              				                        / st 1 Parameter Wr GC[7:0] 01h
	#define CMD_P0_DISPOFF	         0x28 // (Display Off) Write
	#define CMD_P0_DISPON	         0x29 // (Display ON) Write
	#define CMD_P0_TEOFF	         0x34 // (Tearing Effect Line OFF) Write
	#define CMD_P0_TEON	             0x35 // (Tearing Effect Line ON) Write
	#define CMD_P0_MADCTL	         0x36 // (Display Access Control) Write 				                        / st 1 Parameter Wr 0 0 0 0 BGR 0 SS GS xx
	#define CMD_P0_COLMOD	         0x3A // (Interface Pixel Format) Write                                    	    / st 1 Parameter Wr 0 DPI[2:0] 0 0 0 0 70h
	#define CMD_P0_WRDISBV	         0x51 // (Write Display Brightness) Write                                 	    / st 1 Parameter Wr DBV[7:0] xx
	#define CMD_P0_RDDISBV	         0x52 // (Read Display Brightness Value) Write                            	    / st 1 Parameter Rd DBV[7:0] xx
	#define CMD_P0_WRCTRLD	         0x53 // (Write Control Display) Write                                    	    / st 1 Parameter Wr 0 0 BCTRL 0 DD BL 0 0 xx
	#define CMD_P0_RDCTRLD	         0x54 // (Read Control Display Value) Write                               	    / st 1 Parameter Rd 0 0 BCTRL 0 DD BL 0 0 xx
	#define CMD_P0_WRCABC	         0x55 // (Write Content Adaptive Brightness Control) Write                 	    / st 1 Parameter Wr C[7:4] C[3:0] xx
	#define CMD_P0_RDCABC	         0x56 // (Read Content Adaptive Brightness Control) Write                  	    / st 1 Parameter Rd C[7:4] C[3:0] xx
	#define CMD_P0_WRCABCMB	         0x5E // (Write CABC Minimum Brightness) Write                           	    / st 1 Parameter Wr CMB[7:0] xx
	#define CMD_P0_RDCABCMB	         0x5F // (Read CABC Minimum Brightness) Write                            	    / st 1 Parameter Rd CMB[7:0] xx
	#define CMD_P0_RDABCSDR	         0x68 // (Read automatic brightness control self-diagnostic result) Write	    / st 1 Parameter Rd D[7:6] 0 0 0 0 0 0 xx
	#define CMD_P0_RDID1	         0xDA // (Read ID1) Write                                                   	/ st 1 Parameter Rd ID1[7:0] xx
	#define CMD_P0_RDID2	         0xDB // (Read ID2) Write                                                   	/ st 1 Parameter Rd ID2[7:0] xx
	#define CMD_P0_RDID3	         0xDC // (Read ID3) Write                                                   	/ st 1 Parameter Rd ID3[7:0] xx

	#define CMD_P1_RDID4_1	         0x00 // (Read ID 4) Write                                                      / st 1 Parameter Rd ID4[23:16] 98h
	#define CMD_P1_RDID4_2	         0x01 // (Read ID 4) Write                                                      / st 1 Parameter Rd ID4[15:8] 06h
	#define CMD_P1_RDID4_3	         0x02 // (Read ID 4) Write                                                      / st 1 Parameter Rd ID4[7:0] 04h
	#define CMD_P1_IFMODE_1	         0x08 //.1 (Interface Mode Control 1) Write                                     / st 1 Parameter Rd-Wr SDO_STATUS SEPT_SDIO  0 0 0 0 0 0 08h
	#define CMD_P1_IFMODE_2	         0x0A // 2 (Interface Mode Control 2) Write                                     / st 1 Parameter Rd-Wr 2LANE_En  0 0 0 0 0 0 0 00h
	#define CMD_P1_DISCTRL1	         0x20 // (Display Function Control 1) Write                                     / st 1 Parameter Rd-Wr 0 0 0 0 0 0 SYNC 00h 0 MODE
	#define CMD_P1_DISCTRL2	         0x21 // (Display Function Control 2) Write                                     / st 1 Parameter Rd-Wr 0 0 0 0 VSPL HSPL DPL EPL 01h
	#define CMD_P1_PANELCTRL1	     0x22 // (Set panel operation mode1) Write                                      / st 1 Parameter Rd-Wr 0 0 0 BGR_ 0 SS_ GS_ 00h 0 PANEL PANEL PANEL
	#define CMD_P1_PANELCTRL2	     0x23 // (Set panel operation mode2) Write                                      / st 1 Parameter Rd-Wr 0 0 0 0 0 0 REV 0 00h
	#define CMD_P1_Data	             0x24 // Complement Setting Write                                               / st 1 Parameter Rd-Wr 0 0 0 0 0 0 EPF[1:0] 03h
	#define CMD_P1_BLKPRH_1	         0x25 // 1 (Blanking Porch 1) Write                                             / st 1 Parameter Rd-Wr 0 VFP[6:0] 14h
	#define CMD_P1_BLKPRH_2	         0x26 // 2 (Blanking Porch 2) Write                                             / st 1 Parameter Rd-Wr 0 VBP[6:0] 14h
	#define CMD_P1_BLKPRH_3	         0x27 // 3 (Blanking Porch 3) Write                                             / st 1 Parameter Rd-Wr HBP[7:0] 05h
	#define CMD_P1_BLKPRH_4	         0x28 // 4 (Blanking Porch 4) Write                                             / st 1 Parameter Rd-Wr 0 0 0 0 0 0 HBP[9:8] 00h
	#define CMD_P1_RESCTRL	         0x30 // (Resolution Control ) Write                                            / st 1 Parameter Rd-Wr 0 0 0 0 0 RES[2:0] 02h
	#define CMD_P1_INVTR	         0x31 // (Display Inversion Control) Write                                      / st 1 Parameter Rd-Wr 0 0 0 0 NLA[3:0] 00h
	#define CMD_P1_DITHE	         0x34 // (Dithering Enable) Write                                               / st 1 Parameter Rd-Wr 0 0 0 0 0 0 0 DITH_EN 00h
	#define CMD_P1_Source	         0x35 // Signal Adjust Write                                                    / st 1 Parameter Rd-Wr 0 0 0 0 0 CHOPPER SEL_REG[2:0] 06h
	#define CMD_P1_PWCTRL_1	         0x40 // 1 (Power Control 1) Write                                              / st 1 Parameter Rd-Wr EXB1T 0 EXT_CPCK_SEL[1:0] BT [3:0] 15h
	#define CMD_P1_PWCTRL_2	         0x41 // 2 (Power Control 2) Write                                              / st 1 Parameter Rd-Wr 0 DDVDH_CLP[2:0] 0 DDVDL_CLP[2:0] 22h
	#define CMD_P1_PWCTRL_3	         0x42 // 3 (Power Control 3) Write                                              / st 1 Parameter Rd-Wr 0 0 VGH_CP[1:0] 0 0 VGL_CP[1:0] 02h
	#define CMD_P1_PWCTRL_4	         0x43 // 4 (Power Control 4) Write                                              / st 1 Parameter Rd-Wr VGH_CLP_EN  0 0 0 VGH_CLP[3:0] 09h
	#define CMD_P1_PWCTRL_5	         0x44 // 5 (Power Control 5) Write                                              / st 1 Parameter Rd-Wr VGL_CLP_EN  0 0 0 VGL_CLP[3:0] 86h
	#define CMD_P1_PWCTRL_6	         0x45 // 6 (Power Control 6) Write                                              / st 1 Parameter Rd-Wr VGH_REG[3:0] VGL_REG[3:0] 00h
	#define CMD_P1_PWCTRL_7	         0x46 // 7 (Power Control 7) Write                                              / st 1 Parameter Rd-Wr 0 DDVDH_PK1[2:0] 0 DDVDL_PK2[2:0] 33h
	#define CMD_P1_PWCTRL_8	         0x47 // 8 (Power Control 8) Write                                              / st 1 Parameter Rd-Wr 0 VCL_PK3[2:0] 0 VGHL_PK4[2:0] 33h
	#define CMD_P1_PWCTRL_9	         0x50 // 9 (Power Control 9) Write                                              / st 1 Parameter Rd-Wr VREG1[7:0] 78h
	#define CMD_P1_PWCTRL_10         0x51 // 10 (Power Control 10) Write                                            / st 1 Parameter Rd-Wr VREG2[7:0] 78h
	#define CMD_P1_VMCTRL1	         0x52 // (VCOM Control 1) Write                                                 / st 1 Parameter Rd-Wr 0 0 0 0 0 0 0 VCM1[8] 00h
	#define CMD_P1_VMCTRL2	         0x53 // (VCOM Control 2) Write                                                 / st 1 Parameter Rd-Wr VCM1[7:0] 6Fh
	#define CMD_P1_VMCTRL3	         0x54 // (VCOM Control 3) Write                                                 / st 1 Parameter Rd-Wr 0 0 0 0 0 0 0 VCM2[8] 00h
	#define CMD_P1_VMCTRL4	         0x55 // (VCOM Control 4) Write                                                 / st 1 Parameter Rd-Wr VCM2[7:0] 6Fh
	#define CMD_P1_VMCTRL5	         0x56 // (VCOM Control 5) Write                                                 / st 1 Parameter Rd-Wr 0 0 0 NVM2 0 0 0 NVM1 00h
	#define CMD_P1_LVD	             0x57 // (Low Voltage Detection) Write                                          / st 1 Parameter Rd-Wr 0 VDET[2:0] 0 VCORE_VD[2:0] 20h
	#define CMD_P1_ETMOD	         0x58 // (Entry Mode Set) Write                                                 / st 1 Parameter Rd-Wr LVD 0 0 1 0 0 0 DSTB 90h
	#define CMD_P1_Source_1	         0x60 // Timing Adjust 1 Write                                                  / st 1 Parameter Rd-Wr 0 0 SDTI[5:0] 05h
	#define CMD_P1_Source_2	         0x61 // Timing Adjust 2 Write                                                  / st 1 Parameter Rd-Wr 0 0 CRTI[5:0] 05h
	#define CMD_P1_Source_3	         0x62 // Timing Adjust 3 Write                                                  / st 1 Parameter Rd-Wr 0 0 EQTI[5:0] 0Eh
	#define CMD_P1_Source_4	         0x63 // Timing Adjust 4 Write                                                  / st 1 Parameter Rd-Wr 0 0 PCTI[5:0] 05h
	#define CMD_P1_Synchronization_1 0x80 // Timing Adjust 1 Write                                    				/ st 1 Parameter Rd-Wr TOUCH_OPT[1:0] VSOD[1:0] HOSM[1:0] HS_OPT 0 00h
	#define CMD_P1_Synchronization_2 0x81 // Timing Adjust 2 Write                                                  / st 1 Parameter Rd-Wr 0 HSOD[6:0] 05h
	#define CMD_P1_Synchronization_3 0x82 // Timing Adjust 3 Write                                                  / st 1 Parameter Rd-Wr HSOHW[7:0] 19h
	//16 (Positive Gamma Control 1~16)
	#define CMD_P1_PGAMCTRL1	     0xA0 // Rd-Wr 0 0 VP0[5:0] 00h
	#define CMD_P1_PGAMCTRL2		 0xA1 // Rd-Wr 0 0 VP4[5:0] 0Fh
	#define CMD_P1_PGAMCTRL3		 0xA2 // Rd-Wr 0 0 VP8[5:0] 19h
	#define CMD_P1_PGAMCTRL4		 0xA3 // Rd-Wr 0 0 0 VP16[4:0] 12h
	#define CMD_P1_PGAMCTRL5		 0xA4 // Rd-Wr 0 0 0 VP24[4:0] 13h
	#define CMD_P1_PGAMCTRL6		 0xA5 // Rd-Wr 0 0 0 VP52[4:0] 1Ah
	#define CMD_P1_PGAMCTRL7		 0xA6 // Rd-Wr 0 0 0 0 VP80[3:0] 0Dh
	#define CMD_P1_PGAMCTRL8		 0xA7 // Rd-Wr 0 0 0 0 VP108[3:0] 0Ch
	#define CMD_P1_PGAMCTRL9		 0xA8 // Rd-Wr 0 0 0 0 VP147[3:0] 00h
	#define CMD_P1_PGAMCTRL10		 0xA9 // Rd-Wr 0 0 0 0 VP175[3:0] 04h
	#define CMD_P1_PGAMCTRL11		 0xAA // Rd-Wr 0 0 0 VP203[4:0] 04h
	#define CMD_P1_PGAMCTRL12		 0xAB // Rd-Wr 0 0 0 VP231[4:0] 0Dh
	#define CMD_P1_PGAMCTRL13		 0xAC // Rd-Wr 0 0 0 VP239[4:0] 0Bh
	#define CMD_P1_PGAMCTRL14		 0xAD // Rd-Wr 0 0 VP247[5:0] 2Ah
	#define CMD_P1_PGAMCTRL15		 0xAE // Rd-Wr 0 0 VP251[5:0] 20h
	#define CMD_P1_PGAMCTRL16		 0xAF // Rd-Wr 0 0 VP255 [5:0] 00h
	//16(Negative Gamma Correction 1~16)
	#define CMD_P1_NGAMCTRL1	     0xC0 // Rd-Wr 0 0 VN0[5:0] 00h
	#define CMD_P1_NGAMCTRL2		 0xC1 // Rd-Wr 0 0 VN4[5:0] 0Fh
	#define CMD_P1_NGAMCTRL3		 0xC2 // Rd-Wr 0 0 VN8[5:0] 19h
	#define CMD_P1_NGAMCTRL4		 0xC3 // Rd-Wr 0 0 0 VN16[4:0] 12h
	#define CMD_P1_NGAMCTRL5		 0xC4 // Rd-Wr 0 0 0 VN24[4:0] 13h
	#define CMD_P1_NGAMCTRL6		 0xC5 // Rd-Wr 0 0 0 VN52[4:0] 1Ah
	#define CMD_P1_NGAMCTRL7		 0xC6 // Rd-Wr 0 0 0 0 VN80[3:0] 0Dh
	#define CMD_P1_NGAMCTRL8		 0xC7 // Rd-Wr 0 0 0 0 VN108[3:0] 0Ch
	#define CMD_P1_NGAMCTRL9		 0xC8 // Rd-Wr 0 0 0 0 VN147[3:0] 00h
	#define CMD_P1_NGAMCTRL10		 0xC9 // Rd-Wr 0 0 0 0 VN175[3:0] 04h
	#define CMD_P1_NGAMCTRL11		 0xCA // Rd-Wr 0 0 0 VN203[4:0] 04h
	#define CMD_P1_NGAMCTRL12		 0xCB // Rd-Wr 0 0 0 VN231[4:0] 0Dh
	#define CMD_P1_NGAMCTRL13		 0xCC // Rd-Wr 0 0 0 VN239[4:0] 0Bh
	#define CMD_P1_NGAMCTRL14		 0xCD // Rd-Wr 0 0 VN247[5:0] 2Ah
	#define CMD_P1_NGAMCTRL15		 0xCE // Rd-Wr 0 0 VN251[5:0] 20h
	#define CMD_P1_NGAMCTRL16		 0xCF // Rd-Wr 0 0 VN255 [5:0] 00h
	#define CMD_P1_NVMWR_1	         0xE0 // 1 (NV Memory Write 1 ) Write                                         	/ st 1 Parameter Wr PGM_DATA[7:0] 00h
	#define CMD_P1_NVMWR_2	         0xE1 // 2 (NV Memory Write 2 ) Write                                         	/ st 1 Parameter Wr PGM_ADR[7:0] / NVM_READ_ADR[7:0] 00h
	#define CMD_P1_NVMPKEY_1         0xE3 // 1(NV Memory Protection Key 1) Write                                  	/ st 1 Parameter Wr KEY[23:16] XXh
	#define CMD_P1_NVMPKEY_2         0xE4 // 2(NV Memory Protection Key 2) Write                                  	/ st 1 Parameter Wr KEY[15:8] XXh
	#define CMD_P1_NVMPKEY_3         0xE5 // 3(NV Memory Protection Key 3) Write                                  	/ st 1 Parameter Wr KEY[7:0] XXh
	#define CMD_P1_RDNVM1	         0xE6 // (NV Memory Status Read 1 ) Write                                     	/ st 1 Parameter Rd 0 0 ID2_MK[2:0] ID1_ MK [2:0] 00h
	#define CMD_P1_RDNVM2	         0xE7 // (NV Memory Status Read 2 ) Write                                     	/ st 1 Parameter Rd 0 0 0 0 0 ID3_MK[2:0] 00h
	#define CMD_P1_RDNVM3	         0xE8 // (NV Memory Status Read 3 ) Write                                       / st 1 Parameter Rd GMAP_MK GMAN_MK VCM2_MARK[2:0] VCM1_MARK[2:0] 00h
	#define CMD_P1_RDNVM4	         0xE9 // (NV Memory Status Read 4 ) Write                                       / st 1 Parameter Rd OTP_BUSY 0 0 0 0 0 0 0 00h
	#define CMD_P1_RDNVM5	         0xEA // (NV Memory Status Read 5 ) Write                                     	/ st 1 Parameter Rd NVM_READ_DATA[7:0] 00h


	#define CMD_P5_BLCTRL1	         0x00 // (Backlight Control 1) Write                                          	/ st 1 Parameter Rd-Wr PWM_DIV[7:0] E8h
	#define CMD_P5_BLCTRL2	         0x01 // (Backlight Control 2) Write                                          	/ st 1 Parameter Rd-Wr THRES_MOV[3:0] THRES_STILL[3:0] BBh
	#define CMD_P5_BLCTRL3	         0x02 // (Backlight Control 3) Write                                          	/ st 1 Parameter Rd-Wr 0 0 0 0 THRES_UI[3:0] 0Bh
	#define CMD_P5_BLCTRL4	         0x03 // (Backlight Control 4) Write                                          	/ st 1 Parameter Rd-Wr DTH_MOV[3:0] DTH_STILL[3:0] A8h
	#define CMD_P5_BLCTRL5	         0x04 // (Backlight Control 5) Write                                          	/ st 1 Parameter Rd-Wr 0 0 0 0 DTH_UI[3:0] 04h
	#define CMD_P5_BLCTRL6	         0x05 // (Backlight Control 6) Write                                          	/ st 1 Parameter Rd-Wr 0 DIM_MOV[2:0] 0 DIM_STILL[2:0] 43h
	#define CMD_P5_BLCTRL7	         0x06 // (Backlight Control 7) Write                                          	/ st 1 Parameter Rd-Wr DIM_MIN[3:0] 0 DIM_UI[2:0] 02h
	#define CMD_P5_BLCTRL8	         0x07 // (Backlight Control 8) Write                                            / st 1 Parameter Rd-Wr LABC_SRE_THR[3:0] LABC_SRE_ENABLE LEDONR LEDON_PO PWM_POL B0h
	#define CMD_P5_BLCTRL9	         0x09 // (Backlight Control 9) Write                                            / st 1 Parameter Rd-Wr SRECABC_BOOSTEN SRECABC_EN 1 1 1 1 0 0 74h
	#define CMD_P5_BLCTRL10	         0x0C // (Backlight Control 10) Write                                         	/ st 1 Parameter Rd-Wr ALS8BIT[7:0] A0h
	//~3Ch // 1~24 (Color Enhancement Control 1~24 )
	#define CMD_P5_CECTRL_AX1_1		0x25 // Rd-Wr 0 0 0 FIRST_AXIS_1[4:0] 00h
	#define CMD_P5_CECTRL_AX1_2		0x26 // Rd-Wr 0 0 0 FIRST_AXIS_2[4:0] 00h
	#define CMD_P5_CECTRL_AX1_3		0x27 // Rd-Wr 0 0 0 FIRST_AXIS_3[4:0] 00h
	#define CMD_P5_CECTRL_AX1_4		0x28 // Rd-Wr 0 0 0 FIRST_AXIS_4[4:0] 00h
	#define CMD_P5_CECTRL_AX2_1		0x29 // Rd-Wr 0 0 0 SECOND_AXIS_1[4:0] 00h
	#define CMD_P5_CECTRL_AX2_2		0x2A // Rd-Wr 0 0 0 SECOND_AXIS_2[4:0] 00h
	#define CMD_P5_CECTRL_AX2_3		0x2B // Rd-Wr 0 0 0 SECOND_AXIS_3[4:0] 00h
	#define CMD_P5_CECTRL_AX2_4		0x2C // Rd-Wr 0 0 0 SECOND_AXIS_4[4:0] 00h
	#define CMD_P5_CECTRL_AX3_1		0x2D // Rd-Wr 0 0 0 THIRD_AXIS_1[4:0] 00h
	#define CMD_P5_CECTRL_AX3_2		0x2E // Rd-Wr 0 0 0 THIRD_AXIS_2[4:0] 00h
	#define CMD_P5_CECTRL_AX3_3		0x2F // Rd-Wr 0 0 0 THIRD_AXIS_3[4:0] 00h
	#define CMD_P5_CECTRL_AX3_4		0x30 // Rd-Wr 0 0 0 THIRD_AXIS_4[4:0] 00h
	#define CMD_P5_CECTRL_AX4_1		0x31 // Rd-Wr 0 0 0 FOURTH_AXIS_1[4:0] 00h
	#define CMD_P5_CECTRL_AX4_2		0x32 // Rd-Wr 0 0 0 FOURTH_AXIS_2[4:0] 00h
	#define CMD_P5_CECTRL_AX4_3		0x33 // Rd-Wr 0 0 0 FOURTH_AXIS_3[4:0] 00h
	#define CMD_P5_CECTRL_AX4_4		0x34 // Rd-Wr 0 0 0 FOURTH_AXIS_4[4:0] 00h
	#define CMD_P5_CECTRL_AX5_1		0x35 // Rd-Wr 0 0 0 FIFTH_AXIS_1[4:0] 00h
	#define CMD_P5_CECTRL_AX5_2		0x36 // Rd-Wr 0 0 0 FIFTH_AXIS_2[4:0] 00h
	#define CMD_P5_CECTRL_AX5_3		0x37 // Rd-Wr 0 0 0 FIFTH_AXIS_3[4:0] 00h
	#define CMD_P5_CECTRL_AX5_4		0x38 // Rd-Wr 0 0 0 FIFTH_AXIS_4[4:0] 00h
	#define CMD_P5_CECTRL_AX6_1		0x39 // Rd-Wr 0 0 0 SIXTH_AXIS_1[4:0] 00h
	#define CMD_P5_CECTRL_AX6_2		0x3A // Rd-Wr 0 0 0 SIXTH_AXIS_2[4:0] 00h
	#define CMD_P5_CECTRL_AX6_3		0x3B // Rd-Wr 0 0 0 SIXTH_AXIS_3[4:0] 00h
	#define CMD_P5_CECTRL_AX6_4		0x3C // Rd-Wr 0 0 0 SIXTH_AXIS_4[4:0] 00h

	//(GIP Control 1)
	#define CMD_P6_GIPCTRL1_1		0x00 //	Rd-Wr F_TIME_O STV_A_Rise[ 9:8] GIP_0_SET0 - PT
	#define CMD_P6_GIPCTRL1_2		0x01 //	Rd-Wr STV_A_Rise[ 7:0] -
	#define CMD_P6_GIPCTRL1_3		0x02 //	Rd-Wr GIP_0_SET1 -
	#define CMD_P6_GIPCTRL1_4		0x03 //	Rd-Wr GIP_0_SET2 -
	#define CMD_P6_GIPCTRL1_5		0x04 //	Rd-Wr GIP_0_SET3 -
	#define CMD_P6_GIPCTRL1_6		0x05 //	Rd-Wr GIP_0_SET4 -
	#define CMD_P6_GIPCTRL1_7		0x06 //	Rd-Wr CLK_A_Rise[10:8] GIP_0_SET5 -
	#define CMD_P6_GIPCTRL1_8		0x07 //	Rd-Wr CLK_A_Rise[ 7:0] -
	#define CMD_P6_GIPCTRL1_9		0x08 //	Rd-Wr GIP_0_SET6 -
	#define CMD_P6_GIPCTRL1_10		0x09 //	Rd-Wr GIP_0_SET7 -
	#define CMD_P6_GIPCTRL1_11		0x0A //	Rd-Wr GIP_0_SET8 -
	#define CMD_P6_GIPCTRL1_12		0x0B //	Rd-Wr GIP_0_SET9 -
	#define CMD_P6_GIPCTRL1_13		0x0C //	Rd-Wr GIP_0_SET10 -
	#define CMD_P6_GIPCTRL1_14		0x0D //	Rd-Wr GIP_0_SET11 -
	#define CMD_P6_GIPCTRL1_15		0x0E //	Rd-Wr GIP_0_SET12 -
	#define CMD_P6_GIPCTRL1_16		0x0F //	Rd-Wr GIP_0_SET13 -
	#define CMD_P6_GIPCTRL1_17		0x10 //	Rd-Wr GIP_0_SET14 -
	#define CMD_P6_GIPCTRL1_18		0x11 //	Rd-Wr GIP_0_SET15 -
	#define CMD_P6_GIPCTRL1_19		0x12 //	Rd-Wr GIP_0_SET16 -
	#define CMD_P6_GIPCTRL1_20		0x13 //	Rd-Wr GIP_0_SET17 -
	#define CMD_P6_GIPCTRL1_21		0x14 //	Rd-Wr GIP_0_SET18 -
	#define CMD_P6_GIPCTRL1_22		0x15 //	Rd-Wr GIP_0_SET19 -
	#define CMD_P6_GIPCTRL1_23		0x16 //	Rd-Wr GIP_0_SET20 -
	#define CMD_P6_GIPCTRL1_24		0x17 //	Rd-Wr GIP_0_SET21 -
	#define CMD_P6_GIPCTRL1_25		0x18 //	Rd-Wr GIP_0_SET22 -
	#define CMD_P6_GIPCTRL1_26		0x19 //	Rd-Wr GIP_0_SET23 -
	#define CMD_P6_GIPCTRL1_27		0x1A //	Rd-Wr GIP_0_SET24 -
	#define CMD_P6_GIPCTRL1_28		0x1B //	Rd-Wr GIP_0_SET25 -
	#define CMD_P6_GIPCTRL1_29		0x1C //	Rd-Wr GIP_0_SET26 -
	#define CMD_P6_GIPCTRL1_30		0x1D //	Rd-Wr GIP_0_SET27 -
	// (GIP Control 2)
	#define CMD_P6_GIPCTRL2_1 		0x20 // Rd-Wr GIP_1_SET0 -
	#define CMD_P6_GIPCTRL2_2 		0x21 // Rd-Wr GIP_1_SET1 -
	#define CMD_P6_GIPCTRL2_3 		0x22 // Rd-Wr GIP_1_SET2 -
	#define CMD_P6_GIPCTRL2_4 		0x23 // Rd-Wr GIP_1_SET3 -
	#define CMD_P6_GIPCTRL2_5 		0x24 // Rd-Wr GIP_1_SET4 -
	#define CMD_P6_GIPCTRL2_6 		0x25 // Rd-Wr GIP_1_SET5 -
	#define CMD_P6_GIPCTRL2_7 		0x26 // Rd-Wr GIP_1_SET6 -
	#define CMD_P6_GIPCTRL2_8 		0x27 // Rd-Wr GIP_1_SET7 -
	// (GIP Control 3)
	#define CMD_P6_GIPCTRL3_1		0x30 // Rd-Wr GIP_2_SET0 -
	#define CMD_P6_GIPCTRL3_2		0x31 // Rd-Wr GIP_2_SET1 -
	#define CMD_P6_GIPCTRL3_3		0x32 // Rd-Wr GIP_2_SET2 -
	#define CMD_P6_GIPCTRL3_4		0x33 // Rd-Wr GIP_2_SET3 -
	#define CMD_P6_GIPCTRL3_5		0x34 // Rd-Wr GIP_2_SET4 -
	#define CMD_P6_GIPCTRL3_6		0x35 // Rd-Wr GIP_2_SET5 -
	#define CMD_P6_GIPCTRL3_7		0x36 // Rd-Wr GIP_2_SET6 -
	#define CMD_P6_GIPCTRL3_8		0x37 // Rd-Wr GIP_2_SET7 -
	#define CMD_P6_GIPCTRL3_9		0x38 // Rd-Wr GIP_2_SET8 -
	#define CMD_P6_GIPCTRL3_10		0x39 // Rd-Wr GIP_2_SET9 -
	#define CMD_P6_GIPCTRL3_11		0x3A // Rd-Wr GIP_2_SET10 -
	#define CMD_P6_GIPCTRL3_12		0x3B // Rd-Wr GIP_2_SET11 -
	#define CMD_P6_GIPCTRL3_13		0x3C // Rd-Wr GIP_2_SET12 -
	#define CMD_P6_GIPCTRL3_14		0x3D // Rd-Wr GIP_2_SET13 -
	#define CMD_P6_GIPCTRL3_15		0x3E // Rd-Wr GIP_2_SET14 -
	#define CMD_P6_GIPCTRL3_16		0x3F // Rd-Wr GIP_2_SET15 -
	#define CMD_P6_GIPCTRL3_17		0x40 // Rd-Wr GIP_2_SET16 -
	#define CMD_P6_GVLOCTRL_1       0x52 // 1(GOUT_VGLO Control 1) Write                                      		/ st 1 Parameter Rd-Wr 0 0 0 1 GOUT_VGLO_SO [3:0] 11h
	#define CMD_P6_GVLOCTRL_2       0x53 // 2(GOUT_VGLO Control 2) Write                                      		/ st 1 Parameter Rd-Wr 0 0 0 1 GOUT_VGLO_DSP[3:0] 10h
	#define CMD_P6_GVHOCTRL	        0x54 // (GOUT_VGHO Control) Write                                         		/ st 1 Parameter Rd-Wr 0 GOUT_VGHO[2:0] 0 0 0 1 11h

	#define CMD_P7_PWBCTRL	         0x02 // (Power Bias control ) Write                                        	/ st 1 Parameter Rd-Wr 0 DDVDL_CLP_ISC [2:0] 0 DDVDH_CLP_ISC [2:0] 01h
	#define CMD_P7_VCLCTRL	         0x06 // (VCL Control ) Write                                               	/ st 1 Parameter Rd-Wr 0 0 0 VCLOPT 0 0 VCL_CLP[1:0] 01h
	#define CMD_P7_VGLREGEN	         0x17 // (VGL_REG EN) Write                                                		/ st 1 Parameter Rd-Wr VGLREG_EN 0 0 1 0 0 1 0 22h
	#define CMD_P7_VREG12EN	         0x18 // (VREG12OUT ENABLE) Write                                               / st 1 Parameter Rd-Wr 0 0 0 VREG_EN 1 1 0 1 0Dh
	#define CMD_P7_TIMECTRL	         0xE1 // (TIME CONTROL) Write                                              		/ st 1 Parameter Rd-Wr TIME_SHIFT_ERR[3:0] 1 0 0 1 09h

	struct ili9806e_handle
	{
		const struct SPI_SLAVE *spi;
		status_t (*spi_write)(uint16_t data, uint8_t bits);
		status_t (*spi_start)(const struct SPI_SLAVE *spi);
		status_t (*spi_end)(void);
		void (*lcd_reset)(void);
	};

	void ili9806e_send_cmd(struct ili9806e_handle *IL, const uint8_t *data, const uint8_t length);
	void ili9806e_select_page(struct ili9806e_handle *IL, const uint8_t page);
	void ili9806e_init(struct ili9806e_handle *IL);


#endif