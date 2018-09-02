#ifndef _GOODIX_LIB
	#define _GOODIX_LIB
	#include "config.h"
	#include "i2c.h"

	#define GT_CMD_ADDR		0x8040
	#define GT_CMD_READ_COORD	0

	#define GT_CFG_ADDR		0x8047
	#define GT_CFG_LENGTH	186

	#define GT_COORD_ADDR	0x814E
	#define GT_COORD_LENGTH	16

	#define GT_COORD_STATUS_OFFSET	0
	#define GT_COORD_STATUS_DRDY_MSK BIT(7)

	#define GT_MAX_TOUCHES	10

	typedef struct{
		uint8_t reserved;
		uint8_t track_id;
		uint16_t x;
		uint16_t y;
		uint16_t size;
	}gt_coord_t;

	typedef struct{
		i2c_handle_t *i2c;
		uint8_t contacts;
		uint8_t touch_status_reg;
		bool updated;
		void(*callback)(volatile gt_coord_t coords[], uint8_t touches);
		volatile gt_coord_t coords[GT_MAX_TOUCHES];
	}gt_handle_t;

	void gt_handle_irq(gt_handle_t *handle);

#endif