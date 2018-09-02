#ifndef _EXTI_LIB
	#define _EXTI_LIB
	#include "config.h"

	//EXTI
	typedef enum{
		EXTI_PORT_A=0,
		EXTI_PORT_B,
		EXTI_PORT_C,
		EXTI_PORT_D,
		EXTI_PORT_E,
		EXTI_PORT_F,
		EXTI_PORT_G,
		EXTI_PORT_H,
		EXTI_PORT_I,
		EXTI_PORT_J,
		EXTI_PORT_K,
	}exti_port_t;

	#define EXTI_CALLBACK_COUNT	16//24
	#define EXTI_CALLBACK_PINS	16

	extern void(*exti_callback[EXTI_CALLBACK_COUNT])(void);

	void exti_init(void);
	status_t exti_register_callback(uint8_t exti, GPIO_TypeDef *port, bool rising, bool falling, void(*callback)(void));
	status_t exti_reset(uint8_t exti);

	static inline void exti_call_callback(uint8_t exti)
	{
		if(exti_callback[exti]!=NULL)
			exti_callback[exti]();
	};

#endif