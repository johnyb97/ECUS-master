#ifndef _CANDB_HELPER
	#define _CANDB_HELPER
	#include "config.h"
	#include "systick.h"
	#include "can.h"
	#include "global.h"
	#include "misc.h"
	
	enum {
		CAN_MSG_PENDING = 1,
		CAN_MSG_RECEIVED = 2,
		CAN_MSG_MISSED = 4,
	};

	typedef struct {
		uint32_t flags;
		int32_t timeout;
		uint32_t timestamp;

		void (*on_receive)(void);
	} CAN_msg_status_t;

	typedef uint16_t CAN_ID_t;

	#define txGetTimeMillis() SysTick_uptime()

	static inline int txSendCANMessage(CAN_ID_t id, const void* data, size_t length)
	{
		can_msg_t msg={
			.ID.Std=id,
			.IDE=CAN_IDE_STD,
			.RTR=CAN_RTR_DATA,
			.length=length
		};
		memcpy(msg.data, data, length);
		return can_enqueue(&can_dual_handle.can1 , &msg);
	}

	void canInitMsgStatus(CAN_msg_status_t* status, int timeout);
	void canUpdateMsgStatusOnReceive(CAN_msg_status_t* status, uint32_t timestamp);
	
#endif