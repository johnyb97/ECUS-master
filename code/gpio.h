// Copyright (c) 2017 Patrik Bachan
//
// GNU GENERAL PUBLIC LICENSE
//    Version 3, 29 June 2007
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _HARDWARE_LIB
	#define _HARDWARE_LIB

	#include "device.h"
	#include "config.h"

	#define GPIO_MODE_INPUT		0 // 00: Input (reset state)
	#define GPIO_MODE_OUTPUT	1 // 01: General purpose output mode
	#define GPIO_MODE_ALTERNATE	2 // 10: Alternate function mode
	#define GPIO_MODE_ANALOG	3 // 11: Analog mode


	#define GPIO_OTYPE_PP		0 // 0: Output push-pull (reset state)
	#define GPIO_OTYPE_OD		1 // 1: Output open-drain


	#define GPIO_OSPEED_LOW		0 // 00: Low speed
	#define GPIO_OSPEED_MEDIUM	1 // 01: Medium speed
	#define GPIO_OSPEED_FAST		2 // 10: Fast speed
	#define GPIO_OSPEED_HIGH		3 // 11: High speed


	#define GPIO_PUPD_NONE		0 // 00: No pull-up, pull-down
	#define GPIO_PUPD_PU		1 // 01: Pull-up
	#define GPIO_PUPD_PD		2 // 10: Pull-down

	#define GPIO_AF0		0
	#define GPIO_AF1		1
	#define GPIO_AF2		2
	#define GPIO_AF3		3
	#define GPIO_AF4		4
	#define GPIO_AF5		5
	#define GPIO_AF6		6
	#define GPIO_AF7		7
	#define GPIO_AF8		8
	#define GPIO_AF9		9
	#define GPIO_AF10		10
	#define GPIO_AF11		11
	#define GPIO_AF12		12
	#define GPIO_AF13		13
	#define GPIO_AF14		14
	#define GPIO_AF15		15


	void gpio_init(void);

	typedef struct{
		GPIO_TypeDef *const port;
		const uint8_t bit;
	}gpio_port_bit_t;

	#define GPIO_PORT_BIT(PORT, BIT)	(gpio_port_bit_t []){{.port=PORT, .bit=BIT}}

	extern const gpio_port_bit_t *LED1;
	extern const gpio_port_bit_t *LED2;
	extern const gpio_port_bit_t *LED3;
	extern const gpio_port_bit_t *LED4;
	extern const gpio_port_bit_t *LCD_nRST;

	static inline void gpio_set(const gpio_port_bit_t *gpio)
	{
		gpio->port->BSRR = 1<<(gpio->bit);
	}

	static inline void gpio_clr(const gpio_port_bit_t *gpio)
	{
		gpio->port->BSRR = 1<<(gpio->bit+16);
	}
	static inline bool gpio_read(const gpio_port_bit_t *gpio)
	{
		return gpio->port->IDR & 1<<(gpio->bit);
	}

#endif