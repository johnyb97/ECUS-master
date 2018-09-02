#include "candb_helper.h"

void canInitMsgStatus(CAN_msg_status_t* status, int timeout) {
	status->flags = 0;
	status->timeout = timeout;
	status->timestamp = -1;
	status->on_receive = NULL;
}

void canUpdateMsgStatusOnReceive(CAN_msg_status_t* status, uint32_t timestamp) {
	if (status->flags & CAN_MSG_PENDING)
		status->flags |= CAN_MSG_MISSED;

	status->flags |= CAN_MSG_RECEIVED | CAN_MSG_PENDING;
	status->timestamp = timestamp;
}
