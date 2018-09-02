#ifndef _VDCU_PARAMS
	#define _VDCU_PARAMS
	
	#include "candb_structure.h"

	#define VDCU_PARAMETER(NAME, ID, DEFAULT_VALUE, MIN, MAX) (vdcu_param_t[]){{\
		.name=NAME,\
		.value=DEFAULT_VALUE,\
		.min=MIN,\
		.max=MAX,\
		.id=ID,\
		.state=PARAM_STATE_IDLE,\
		.last_change_id=0,\
		.retry_counter=0,\
	}}

	typedef enum{
		PARAM_STATE_IDLE=0,
		PARAM_STATE_MODIFIED,//needs to be sent due to value change
		PARAM_STATE_UPDATE,//needs to be sent due to periodit update
		PARAM_STATE_SENT,//update sent
		PARAM_STATE_CONFIRMED_MATCH,//received ACK, value confirmed
		PARAM_STATE_CONFIRMED_MISMATCH,//received ACK, value different
		PARAM_STATE_TIMEOUT,//no ack received until timeout occured
		PARAM_STATE_FAILED//no ack received after all retries
	}param_state_t;

	typedef struct{
		volatile uint32_t sent_ts;
		const char *name;
		volatile uint16_t value;
		const uint16_t min;
		const uint16_t max;
		volatile param_state_t state;
		volatile uint8_t last_change_id;
		volatile uint8_t retry_counter;
		uint8_t id;
	}vdcu_param_t;

	void vdcu_param_change(vdcu_param_t *parameter, uint16_t value);
	void vdcu_param_process(vdcu_param_t *const *parameter_set);
	void vdcu_param_ack_handler(const struct candb_msg *msg, vdcu_param_t *const *current_parameter_set);
	void vdcu_param_periodic_update(vdcu_param_t *const *parameter_set);
	vdcu_param_t *vdcu_param_get(vdcu_param_t *const *parameter_set, uint8_t id);
	
#endif