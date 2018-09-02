#include "can.h"
#include "config.h"
#include "debug.h"
#include "gpio.h"
#include "clock.h"

#ifdef DEBUG_CAN
	#pragma message "CAN debug enabled!"
	#include "debug_enable.h"
#endif

void can_filter_init(can_dual_handle_t *handle)
{
	DEBUG_STR("CAN FILTER INIT\n");
	CAN_TypeDef *can = handle->can1.can;

	bit_set(can->FMR, CAN_FMR_FINIT);
	bit_mod(can->FMR, CAN_FMR_CAN2SB_Msk ,handle->can1_filters_count<<CAN_FMR_CAN2SB_Pos);

	for(uint8_t idx=0; idx<28; idx++)
	{
		DEBUG_STR("SLOT: ");
		DEBUG_NUM(idx,2);
		const can_filter_t *filter = &handle->filter[idx];
		if(filter->active)
		{
			DEBUG_STR(" ACTIVE ");
			//configure
			if(filter->mode == CAN_FILTER_MODE_LIST)
				bit_set(can->FM1R, 1<<idx);

			if(filter->scale == CAN_FILTER_SCALE_32bit)
				bit_set(can->FS1R, 1<<idx);
			
			if(filter->fifo != 0)
				bit_set(can->FFA1R, 1<<idx);
			
			//fill settings (mask, id)
			uint32_t R1=0;
			uint32_t R2=0;
			if((filter->mode == CAN_FILTER_MODE_LIST) && (filter->scale == CAN_FILTER_SCALE_32bit))
			{
				DEBUG_STR("LIST 32");
				R1=filter->specific.list_32[0];
				R2=filter->specific.list_32[1];
			}
			else if((filter->mode == CAN_FILTER_MODE_LIST) && (filter->scale == CAN_FILTER_SCALE_16bit))
			{
				DEBUG_STR("LIST 16");
				R1=(uint32_t)filter->specific.list_16[1]<<16 | filter->specific.list_16[0];
				R2=(uint32_t)filter->specific.list_16[3]<<16 | filter->specific.list_16[2];
			}
			else if((filter->mode == CAN_FILTER_MODE_MASK) && (filter->scale == CAN_FILTER_SCALE_32bit))
			{
				DEBUG_STR("MASK 32");
				R1=filter->specific.mask_32.id;
				R2=filter->specific.mask_32.mask;
			}
			else if((filter->mode == CAN_FILTER_MODE_MASK) && (filter->scale == CAN_FILTER_SCALE_16bit))
			{
				DEBUG_STR("MASK 16");
				R1=((uint32_t)filter->specific.mask_16[0].mask)<<16 | filter->specific.mask_16[0].id;
				R2=((uint32_t)filter->specific.mask_16[1].mask)<<16 | filter->specific.mask_16[1].id;
			}
			else
			{
				DEBUG_CRITICAL_STR("UNKNOWN CAN FILTER CONFIG!\n");
				bit_clr(can->FA1R, 1<<idx);//deactivate this slot
				continue;//finish for cycle prematurely
			}
			DEBUG_NL();

			can->sFilterRegister[idx].FR1 = R1;
			can->sFilterRegister[idx].FR2 = R2;


			//activate
			bit_set(can->FA1R, 1<<idx);
		}
		else
		{
			DEBUG_STR(" INACTIVE\n");
			bit_clr(can->FA1R, 1<<idx);
		}
			
	}
	bit_clr(can->FMR, CAN_FMR_FINIT);
}

void can_dual_init(can_dual_handle_t *handle)
{
	can_init(&handle->can1);
	can_init(&handle->can2);
	can_filter_init(handle);
}

void can_init(can_handle_t *handle)
{
	DEBUG_CRITICAL_STR("CAN init\n");

	bit_clr(handle->can->MCR, CAN_MCR_SLEEP);
	bit_set(handle->can->MCR, CAN_MCR_INRQ);//request initialization

	uint16_t t=0;
	while(bit_get(handle->can->MSR,CAN_MSR_INAK)!=CAN_MSR_INAK)//wait for init flag set
		t++;

	DEBUG_STR("CAN ?->I took: ");
	DEBUG_NUM(t, 3);
	DEBUG_NL();

	// bit_set(handle->can->MCR, CAN_MCR_NART);
	bit_set(handle->can->MCR, CAN_MCR_ABOM);//enable automatim bus off mgmt
	// bit_set(handle->can->IER, CAN_IER_ERRIE|CAN_IER_BOFIE|CAN_IER_EWGIE|CAN_IER_LECIE);//enable error interrupts

	if(handle->txcb != NULL)
	{
		// bit_set(handle->can->MCR, CAN_MCR_TXFP);//fifo Priority driven by the request order (chronologically)
		bit_set(handle->can->IER, CAN_IER_TMEIE);
	}

	if(handle->rxcb != NULL)
	{
		bit_set(handle->can->IER, CAN_IER_FMPIE0);//enable interrupt: TX empty , FIFO0 level above threshold
	}

	//prescaler http://www.bittiming.can-wiki.info/
	// 50MHz clk
	// | Bit Rate	| accuracy	| PSC	| num of tq	| Seg 1(Prop+Phase)	| Seg 2	| Sample Point at	| Register CAN_BTR	|
	// | 500		| 0.0000	| 5		| 20		| 16				| 3		| 85.0				| 0x002f0004
	// | 500		| 0.0000	| 10	| 10		| 7					| 2		| 80.0				| 0x00160009
	// | 500		| 0.0000	| 10	| 10		| 8					| 1		| 90.0				| 0x00070009


	#if F_APB1 != (50*1000000UL)
		#error "CAN timing needs adjustment!"
	#endif

	//TODO("put can timing config into handle?")

	// https://vector.com/portal/medien/cmc/application_notes/AN-AND-1-106_Basic_CAN_Bit_Timing.pdf

	handle->can->BTR =	( 5-1)<<CAN_BTR_BRP_Pos |
						(15-1)<<CAN_BTR_TS1_Pos |
						( 4-1)<<CAN_BTR_TS2_Pos |
						( 3-1)<<CAN_BTR_SJW_Pos	;// | CAN_BTR_LBKM;

	//go to normal
	bit_clr(handle->can->MCR, CAN_MCR_INRQ);//leave init mode

	t=0;
	while(bit_get(handle->can->MSR,CAN_MSR_INAK)==CAN_MSR_INAK)//wait for init flag clr
		t++;

	DEBUG_STR("CAN I->N took: ");
	DEBUG_NUM(t, 3);
	DEBUG_NL();
}

static void can_send(can_msg_t *tx_msg, CAN_TxMailBox_TypeDef *tx_mb)
{
	//payload length
	tx_mb->TDTR = tx_msg->length<<CAN_TDT0R_DLC_Pos;
	//data
	tx_mb->TDLR = ((uint32_t*)(tx_msg->data))[0];
	tx_mb->TDHR = ((uint32_t*)(tx_msg->data))[1];

	uint32_t config=0;
	if(tx_msg->IDE == CAN_IDE_STD)
		config = tx_msg->ID.Std<<CAN_TI0R_STID_Pos;
	else
		config = tx_msg->ID.Ext<<CAN_TI0R_EXID_Pos | CAN_TI0R_IDE;
	
	if(tx_msg->RTR == CAN_RTR_REMOTE)
		bit_set(config, CAN_TI0R_RTR);

	tx_mb->TIR = config | CAN_TI0R_TXRQ;
}

static void can_dispatch(can_handle_t *handle)
{
	DEBUG_STR("DISPATCH\n");
	for(uint8_t mb=0; mb<3 && cb_used_space(handle->txcb)>0 ; mb++)
	{
		DEBUG_STR("CAN tx mbox ");
		DEBUG_NUM(mb, 1);
		if(bit_get(handle->can->sTxMailBox[mb].TIR, CAN_TI0R_TXRQ)==0)
		{
			DEBUG_STR(" empty\n");
			can_msg_t tx_msg;
			if(cb_pop(handle->txcb, (void*)(&tx_msg))==STAT_OK)
				can_send( &tx_msg, &handle->can->sTxMailBox[mb]);
		}
		else
		{
			DEBUG_STR(" BUSY\n");
		}
	}
}


uint8_t can_enqueue(can_handle_t  *handle, can_msg_t *tx_msg)
{
	// if(handle->tx_overflow)
	// {
	// 	return STAT_ERR_OVERFLOW;
	// }

	if(cb_empty_space(handle->txcb)>0)
	{
		status_t status=cb_push(handle->txcb, (void*)(tx_msg));
		if(status!=STAT_OK)
		{
			DEBUG_CRITICAL_STR("CB ERROR\n");
			return status;
		}
		DEBUG_STR("CAN msg enqueued\n");
		// DEBUG_CH('M');
		can_dispatch(handle);
		return STAT_OK;
	}
	else
	{
		DEBUG_STR("CAN queue full!\n");
		// handle->tx_overflow=true;
		return STAT_ERR_OVERFLOW;
	}
}

void can_tx_irq_handler(can_handle_t *handle)
{
	handle->can->TSR = CAN_TSR_RQCP0 | CAN_TSR_RQCP1 | CAN_TSR_RQCP2; //clear all flags triggering this interrupt
	DEBUG_STR("CAN IRQ TX\n");
	can_dispatch(handle);
}

void can_rx_irq_handler(can_handle_t *handle)
{
	DEBUG_STR("CAN IRQ RX ");
	if(handle->can == CAN1)
		DEBUG_STR("1\n");
	else
		DEBUG_STR("2\n");
		
	while(bit_get(handle->can->RF0R, CAN_RF0R_FMP0_Msk))
	{
		can_msg_t msg;
		if(bit_get(handle->can->sFIFOMailBox[0].RIR, CAN_RI0R_IDE_Msk))
		{
			msg.IDE = CAN_IDE_EXT;
			msg.ID.Ext = (handle->can->sFIFOMailBox[0].RIR&CAN_RI0R_EXID_Msk)>>CAN_RI0R_EXID_Pos;
		}
		else
		{
			msg.IDE = CAN_IDE_STD;
			msg.ID.Std = (handle->can->sFIFOMailBox[0].RIR&CAN_RI0R_STID_Msk )>>CAN_RI0R_STID_Pos;
		}

		if(bit_get(handle->can->sFIFOMailBox[0].RIR, CAN_RI0R_RTR_Msk))
			msg.RTR = CAN_RTR_REMOTE;
		else
			msg.RTR = CAN_RTR_DATA;

		msg.length = (handle->can->sFIFOMailBox[0].RDTR&CAN_RDT0R_DLC_Msk)>>CAN_RDT0R_DLC_Pos;
		
		((uint32_t*)(msg.data))[0] = handle->can->sFIFOMailBox[0].RDLR;
		((uint32_t*)(msg.data))[1] = handle->can->sFIFOMailBox[0].RDHR;

		//release receive mailbox
		bit_set(handle->can->RF0R, CAN_RF0R_RFOM0);
		cb_push(handle->rxcb, &msg);
		
		DEBUG_STR("FIFO: ");
		DEBUG_NUM(cb_used_space(handle->rxcb),3);
		DEBUG_CH('/');
		DEBUG_NUM(handle->rxcb->capacity,3);
		DEBUG_NL();
	} 
}
