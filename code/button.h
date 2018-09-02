#ifndef _BUTTON_LIB
	#define _BUTTON_LIB

	#include "gpio.h"
	#include <inttypes.h>

	typedef enum{
		BTN_EVT_PRESS=1,
		BTN_EVT_RELEASE=2,
		BTN_EVT_CLICK=4,//press and release below hold timeout
		BTN_EVT_CLICK_LONG=8,
		BTN_EVT_HOLD_TIMEOUT=16,
		BTN_EVT_ALL=(32-1)
	}button_event_t;

	struct button{
		const char *const name;
		const uint8_t id;
		void (*callback)(struct button *btn, button_event_t event);
		gpio_port_bit_t gpio;
		uint32_t clicks;
		uint16_t hold_time;
		uint16_t click_long_threshold;
		uint16_t hold_threshold;
		button_event_t sensitive;
		bool active_high;
	};

	typedef struct button button_t;

	void button_process(button_t *const *buttons);
	
#endif