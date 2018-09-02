#ifndef _CAN_LIB
#define _CAN_LIB

#include "config.h"
#include "device.h"
#include "circular_buffer.h"

//left aligned!
#define CAN_FILTER_LIST32(fifo_num, id32_1, id32_2)	{\
	.mode=CAN_FILTER_MODE_LIST,\
	.scale=CAN_FILTER_SCALE_32bit,\
	.fifo=fifo_num,\
	.specific.list_32={id32_1, id32_2},\
	.active=true}
#define CAN_FILTER_LIST16(fifo_num, id32_1, id32_2, id32_3, id32_4)	{\
	.mode=CAN_FILTER_MODE_LIST,\
	.scale=CAN_FILTER_SCALE_16bit,\
	.fifo=fifo_num,\
	.specific.list_16={id16_1, id16_2, id16_3, id16_4},\
	.active=true}
#define CAN_FILTER_MASK32(fifo_num, id32, mask32)	{\
	.mode=CAN_FILTER_MODE_MASK,\
	.scale=CAN_FILTER_SCALE_32bit,\
	.fifo=fifo_num,\
	.specific.mask_32={.mask=mask32, .id=id32},\
	.active=true}
#define CAN_FILTER_MASK16(fifo_num, id16_1, mask16_1, id16_2, mask16_2)	{\
	.mode=CAN_FILTER_MODE_MASK,\
	.scale=CAN_FILTER_SCALE_16bit,\
	.fifo=fifo_num,\
	.specific.mask_16={{.mask=mask16_1, .id=id16_1}, {.mask=mask16_2, .id=id16_2}}\
	.active=true}

typedef enum{
	CAN_IDE_STD=0,
	CAN_IDE_EXT=1
}CAN_IDE_t;

typedef enum{
	CAN_RTR_DATA=0,
	CAN_RTR_REMOTE=1
}CAN_RTR_t;

typedef struct{
	union{
		uint32_t Ext;
		uint16_t Std;
	}ID;
	CAN_IDE_t IDE;
	CAN_RTR_t RTR;
	uint8_t data[8];
	uint8_t length;
}can_msg_t;

typedef struct{
	circular_buffer_t *txcb;
	circular_buffer_t *rxcb;
	CAN_TypeDef *can;	
}can_handle_t;

typedef enum{
	CAN_FILTER_MODE_MASK=0,
	CAN_FILTER_MODE_LIST=1
}can_filter_mode_t;

typedef enum{
	CAN_FILTER_SCALE_16bit=0,
	CAN_FILTER_SCALE_32bit=1
}can_filter_scale_t;

typedef struct{
	can_filter_mode_t mode;//mask/list
	can_filter_scale_t scale;//
	uint8_t fifo;
	union{
		uint32_t list_32[2];
		uint16_t list_16[4];
		struct{
			uint32_t id;
			uint32_t mask;
		}mask_32;
		struct{
			uint16_t id;
			uint16_t mask;
		}mask_16[2];
	}specific;
	bool active;
}can_filter_t;

typedef struct{
	can_handle_t can1;
	can_handle_t can2;
	const uint8_t can1_filters_count;
	const can_filter_t filter[28];
}can_dual_handle_t;


void can_init(can_handle_t *handle);
void can_dual_init(can_dual_handle_t *handle);
uint8_t can_enqueue(can_handle_t  *handle, can_msg_t *tx_msg);
void can_flush_tx_queue(can_handle_t *handle);
void can_tx_irq_handler(can_handle_t *handle);
void can_rx_irq_handler(can_handle_t *handle);

#endif