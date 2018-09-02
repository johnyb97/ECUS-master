#ifndef _LCD_LIB
	#define _LCD_LIB

	#include "config.h"
	#include "fonts.h"
	#include "debug.h"

	/*
	* Overlap means drawing additional pixel when changing minor direction
	* Needed for drawThickLine, otherwise some pixels will be missing in the thick line
	*/
	#define LINE_OVERLAP_NONE 0 	// No line overlap, like in standard Bresenham
	#define LINE_OVERLAP_MAJOR 0x01 // Overlap - first go major then minor direction. Pixel is drawn as extension after actual line
	#define LINE_OVERLAP_MINOR 0x02 // Overlap - first go minor then major direction. Pixel is drawn as extension before next line
	#define LINE_OVERLAP_BOTH 0x03  // Overlap - both

	#define LINE_THICKNESS_MIDDLE 0                 // Start point is on the line at center of the thick line
	#define LINE_THICKNESS_DRAW_CLOCKWISE 1         // Start point is on the counter clockwise border line
	#define LINE_THICKNESS_DRAW_COUNTERCLOCKWISE 2 // Start point is on the clockwise border line

	typedef enum{
		LCD_PIX_FMT_ARGB8888=0,
		LCD_PIX_FMT_RGB888,
		LCD_PIX_FMT_RGB565,
		LCD_PIX_FMT_ARGB1555,
		LCD_PIX_FMT_ARGB4444,
		LCD_PIX_FMT_L8,
		LCD_PIX_FMT_AL44,
		LCD_PIX_FMT_AL88,
		LCD_PIX_FMT_L4,
		LCD_PIX_FMT_A8,
		LCD_PIX_FMT_A4
	} lcd_pix_fmt_t;

	typedef struct{
		int16_t x_min;
		int16_t x_max;
		int16_t y_min;
		int16_t y_max;
	}boundaries_t;

	typedef struct{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	}color_t;

	#define LCD_COLOR(R,G,B) (color_t){.r=R, .g=G, .b=B, .a=255}
	#define LCD_COLOR_A(R,G,B,A) (color_t){.r=R, .g=G, .b=B, .a=A}

	static inline uint32_t lcd_color_to_raw(color_t color, lcd_pix_fmt_t fmt)
	{
		uint32_t _R=color.r;
		uint32_t _G=color.g;
		uint32_t _B=color.b;
		uint32_t _A=color.a;
		switch(fmt)
		{
			case LCD_PIX_FMT_ARGB8888:
				return (_A<<16) | (_R<<16) | (_G<<8) | _B;
			case LCD_PIX_FMT_RGB888:
				return (_R<<16) | (_G<<8) | _B;
			case LCD_PIX_FMT_RGB565:
				return ((_R>>3)<<11) | ((_G>>2)<<5) | (_B>>3);
			case LCD_PIX_FMT_ARGB1555:
				return ((_A>>7)<<15) | ((_R>>3)<<10) | ((_G>>3)<<5) | (_B>>3);
			case LCD_PIX_FMT_ARGB4444:
				return ((_A>>4)<<12) | ((_R>>4)<<8) | ((_G>>4)<<4) | (_B>>4);
			case LCD_PIX_FMT_A8:
				return _A;
			case LCD_PIX_FMT_A4:
				return (_A>>4);

			case LCD_PIX_FMT_L8:
			case LCD_PIX_FMT_AL44:
			case LCD_PIX_FMT_AL88:
			case LCD_PIX_FMT_L4:
				DEBUG_CRITICAL_STR("CLUT pix FMT output not available\n");
			
		}
		return 0;
	} 


	static inline uint8_t pix_fmt_to_size(lcd_pix_fmt_t fmt)
	{
		switch(fmt)
		{
			case LCD_PIX_FMT_ARGB8888:
				return 4;

			case LCD_PIX_FMT_RGB888:
				return 3;

			case LCD_PIX_FMT_RGB565:
			case LCD_PIX_FMT_ARGB1555:
			case LCD_PIX_FMT_ARGB4444:
			case LCD_PIX_FMT_AL88:
				return 2;

			case LCD_PIX_FMT_L8:
			case LCD_PIX_FMT_AL44:
				return 1;

			default:
				return 0;
		}
	};

	void draw_wait_for_complete(void);

	void draw_string(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		const font_t *fnt, const char *str );

	void draw_char(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		const font_char_t *ch);

	void draw_circle_filled(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		uint16_t radius);
	
	void draw_rectangle(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		uint16_t width, uint16_t height, uint16_t thickness);

	void draw_rectangle_filled(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		uint16_t width, uint16_t height);

	static inline void draw_hline(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		int16_t width)
		{draw_rectangle_filled(FB_addr, pix_fmt, color , scissors, x, y, width, 1);}

	static inline void draw_vline(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		int16_t height)
		{draw_rectangle_filled(FB_addr, pix_fmt, color , scissors, x, y, 1, height);}

	void draw_rectangle_filled_rounded(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		uint16_t width, uint16_t height, uint16_t radius);


	void draw_point(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y\
		);
	
	void draw_line(
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x_start, int16_t y_start,\
	int16_t x_end, int16_t y_end, uint8_t thickness, uint8_t thickness_mode);

	void draw_bitmap(\
		uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		lcd_pix_fmt_t src_pix_fmt, const void *data, uint16_t w, uint16_t h);


#endif