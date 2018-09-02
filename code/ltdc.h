#ifndef _LTDC_LIB
	#define _LTDC_LIB

	#include "config.h"
	#include "lcd.h"

	typedef struct{
		uint32_t address;
		lcd_pix_fmt_t pix_fmt;
		LTDC_Layer_TypeDef *regs;
		bool enabled;
	}ltdc_layer_t;

	#define LCD_BUFFERS	2

	typedef struct{
		//const uint8_t buffers;
		volatile enum{
			LCD_FB_STATE_IDLE=0,
			LCD_FB_STATE_READY_TO_DISPLAY,
			LCD_FB_STATE_DISPLAYING,
			LCD_FB_STATE_READY_TO_DRAW,
			LCD_FB_STATE_DRAWING,
		}state;
		ltdc_layer_t layer[2];//ltdc suports 2 layers
	}ltdc_fb_t;

	extern ltdc_fb_t lcd_fb[LCD_BUFFERS];

	void ltdc_start(ltdc_fb_t *initial_buffer);
	void ltdc_init(void);
	ltdc_fb_t *ltdc_get_drawable_fb(ltdc_fb_t fb_array[]);
	void ltdc_release_fb_to_display(ltdc_fb_t **fb_ptr);

#endif