#ifndef _QEI_LIB
	#define _QEI_LIB

	#include "gpio.h"
	
	#include <inttypes.h>
	#include <stdbool.h>

	//binary mask!
	typedef enum{
		QEI_EVT_INC=1,
		QEI_EVT_DEC=2,
	}qei_event_t;


	typedef struct{
		const gpio_port_bit_t gpio_edge;
		const gpio_port_bit_t gpio_lvl;
		uint32_t position;
		void (*event_callback)(qei_event_t event, uint32_t abs_position);
		qei_event_t sensitive;
		bool reverse_direction;
		bool act_on_rising;
		bool act_on_falling;
		const uint8_t evt_prescaler;
		int8_t evt_cnt;
	}qei_handle_t;

	void qei_callback(qei_handle_t *qei);

#endif