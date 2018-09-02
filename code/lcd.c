#include "lcd.h"			

#include "debug_enable.h"

#define X_MIN	0
#define X_MAX	LCD_WIDTH
#define Y_MIN	0
#define Y_MAX	LCD_HEIGHT

void draw_wait_for_complete(void)
{
	while(bit_get(DMA2D->CR, DMA2D_CR_START))
		NOP;
}

typedef struct{
	uint16_t x_skipped;
	uint16_t width;
	uint16_t y_skipped;
	uint16_t height;
	bool	valid;
}scissor_result_t;

static scissor_result_t scissor_area_validate(int16_t x, int16_t y, int16_t width, int16_t height, const boundaries_t *scissors)
{
	scissor_result_t scissor_result={.valid=false};

	if(scissors == NULL)//scissors ignored
	{
		scissor_result.valid=true;
		scissor_result.x_skipped=0;
		scissor_result.y_skipped=0;
		scissor_result.width=width;
		scissor_result.height=height;
		return scissor_result;
	}

	if(x+width < scissors->x_min || x > scissors->x_max)//nothing in visible area
		return scissor_result;
	
	if(y+height < scissors->y_min || y > scissors->y_max)//nothing in visible area
		return scissor_result;

	scissor_result.x_skipped = max(0, scissors->x_min-x);
	scissor_result.y_skipped = max(0, scissors->y_min-y);

	scissor_result.width = width;
	if(x < scissors->x_min)
		scissor_result.width -= scissors->x_min-x;//shorten drawn width by leading part out of visible area
	if(x+scissor_result.width > scissors->x_max)
		scissor_result.width -= (x+scissor_result.width)-scissors->x_max;//shorten drawn width by trailing part out of visible area
	
	scissor_result.height = height;
	if(y < scissors->y_min)
		scissor_result.height -= scissors->y_min-y;//shorten drawn width by leading part out of visible area
	if(y+scissor_result.height > scissors->y_max)
		scissor_result.height -= (y+scissor_result.height)-scissors->y_max;//shorten drawn width by trailing part out of visible area
	
	scissor_result.valid=true;
	return scissor_result;
}

void draw_circle_filled(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, int16_t x, const int16_t y,\
		const uint16_t radius)
{
	int32_t  decision;     /* Decision Variable */ 
	uint32_t  current_x;   /* Current X Value */
	uint32_t  current_y;   /* Current Y Value */

	decision = 3 - (radius << 1);

	current_x = 0;
	current_y = radius;

	x += radius;

	while (current_x <= current_y)
	{
		if(current_y > 0) 
		{
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_y, y + current_x - radius, 2*(current_y - radius));
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_y, y - current_x + radius, 2*(current_y - radius));
		}

		if(current_x > 0) 
		{
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_x, y - current_y + radius, 2*(current_x - radius));
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_x, y + current_y - radius, 2*(current_x - radius));
		}
		if (decision < 0)
		{ 
			decision += (current_x << 2) + 6;
		}
		else
		{
			decision += ((current_x - current_y) << 2) + 10;
			current_y--;
		}
		current_x++;
	}
}

static void draw_point_fast(const uint32_t FB_addr, uint8_t pix_size, uint32_t color_raw, const int16_t x, const int16_t y)
{
	uint32_t addr = FB_addr+(x+(LCD_WIDTH*(uint32_t)y))*pix_size;//calculate correct start address from DMA using X a Y coordinates
	
	switch(pix_size)
	{
		case 1:
			*(uint8_t*)addr=color_raw;
			break;
		
		case 2:
			*(uint16_t*)addr=color_raw;
			break;
		
		case 4:
			*(uint32_t*)addr=color_raw;
			break;
	}
}

void draw_point(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, const int16_t x, const int16_t y)
{
	scissor_result_t sc_result = scissor_area_validate(x, y, 0, 0, scissors);
	if(!sc_result.valid)
		return;

	uint8_t pix_size= pix_fmt_to_size(pix_fmt);
	//do not even draw if x or y are outside of LCD

	uint32_t addr = FB_addr+(x+(LCD_WIDTH*(uint32_t)y))*pix_size;//calculate correct start address from DMA using X a Y coordinates
	
	switch(pix_size)
	{
		case 1:
			*(uint8_t*)addr=lcd_color_to_raw(color, pix_fmt);
			break;
		
		case 2:
			*(uint16_t*)addr=lcd_color_to_raw(color, pix_fmt);
			break;
		
		case 4:
			*(uint32_t*)addr=lcd_color_to_raw(color, pix_fmt);
			break;
	}
}

void draw_rectangle_filled(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, const int16_t x, const int16_t y,\
		const uint16_t width, const uint16_t height)
{
	uint8_t pix_size= pix_fmt_to_size(pix_fmt);
	//do not even draw if x or y are outside of LCD

	scissor_result_t sc_result = scissor_area_validate(x, y, width, height, scissors);
	if(!sc_result.valid)
		return;

	draw_wait_for_complete();
	DMA2D->OMAR = FB_addr+(x+sc_result.x_skipped+(LCD_WIDTH*((uint32_t)y+sc_result.y_skipped)))*pix_size;
	DMA2D->OOR = (LCD_WIDTH-sc_result.width)<<DMA2D_OOR_LO_Pos;
	DMA2D->OPFCCR = pix_fmt<<DMA2D_OPFCCR_CM_Pos;
	DMA2D->OCOLR = lcd_color_to_raw(color, pix_fmt);
	DMA2D->NLR = (sc_result.width<<DMA2D_NLR_PL_Pos) | (sc_result.height<<DMA2D_NLR_NL_Pos);
	bit_mod(DMA2D->CR, DMA2D_CR_MODE_Msk, (3<<DMA2D_CR_MODE_Pos));
	bit_set(DMA2D->CR, DMA2D_CR_START);
}

void draw_rectangle(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		uint16_t width, uint16_t height, const uint16_t thickness)
{
	x-=thickness;
	y-=thickness;
	width+=2*thickness;
	height+=2*thickness;

	scissor_result_t sc_result = scissor_area_validate(x, y, width, height, scissors);
	if(!sc_result.valid)//do not even draw if x or y are outside of LCD
		return;

	//top
	draw_rectangle_filled(FB_addr, pix_fmt, color, scissors, x, y, width, thickness);
	//bottom
	draw_rectangle_filled(FB_addr, pix_fmt, color, scissors, x, y+height-thickness, width, thickness);
	//left
	draw_rectangle_filled(FB_addr, pix_fmt, color, scissors, x, y+thickness, thickness, height-2*thickness);
	//right
	draw_rectangle_filled(FB_addr, pix_fmt, color, scissors, x+width-thickness, y+thickness, thickness, height-2*thickness);
}


void draw_rectangle_filled_rounded(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, int16_t x, const int16_t y,\
		const uint16_t width, const uint16_t height, const uint16_t radius)
{
	int32_t  decision;     /* Decision Variable */ 
	uint32_t  current_x;   /* Current X Value */
	uint32_t  current_y;   /* Current Y Value */

	decision = 3 - (radius << 1);

	current_x = 0;
	current_y = radius;

	draw_rectangle_filled(FB_addr, pix_fmt, color, scissors, x, y + radius, width, height - 2*radius);	

	x += radius;

	while (current_x <= current_y)
	{
		if(current_y > 0) 
		{
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_y, y + current_x + height - radius, 2*(current_y - radius) + width);
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_y, y - current_x + radius, 2*(current_y - radius) + width);
		}

		if(current_x > 0) 
		{
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_x, y - current_y + radius, 2*(current_x - radius) + width);
			draw_hline(FB_addr, pix_fmt, color, scissors, x - current_x, y + current_y + height - radius, 2*(current_x - radius) + width);
		}
		if (decision < 0)
		{ 
			decision += (current_x << 2) + 6;
		}
		else
		{
			decision += ((current_x - current_y) << 2) + 10;
			current_y--;
		}
		current_x++;
	}
}

void draw_bitmap(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		const lcd_pix_fmt_t src_pix_fmt, const void *data, uint16_t w, uint16_t h)
{
	scissor_result_t sc_result = scissor_area_validate(x, y, w, h, scissors);
	if(!sc_result.valid)
		return;

	int32_t FB_addr_xy = FB_addr+(x+sc_result.x_skipped+(LCD_WIDTH*((uint32_t)y+sc_result.y_skipped)))*pix_fmt_to_size(pix_fmt);//calculate correct start address from DMA using X a Y coordinates
	draw_wait_for_complete();

	DMA2D->FGMAR = (uint32_t)data+sc_result.x_skipped+(sc_result.y_skipped*w) ;
	DMA2D->FGOR = w-sc_result.width;
	DMA2D->FGPFCCR = src_pix_fmt<<DMA2D_FGPFCCR_CM_Pos;
	DMA2D->FGCOLR = lcd_color_to_raw(color, LCD_PIX_FMT_RGB888);

	DMA2D->BGMAR = FB_addr_xy;
	DMA2D->BGOR = (LCD_WIDTH-sc_result.width)<<DMA2D_BGOR_LO_Pos;
	DMA2D->BGPFCCR = pix_fmt<<DMA2D_BGPFCCR_CM_Pos;
	DMA2D->BGCOLR = 0;

	DMA2D->OMAR = FB_addr_xy;
	DMA2D->OOR = (LCD_WIDTH-sc_result.width)<<DMA2D_OOR_LO_Pos;
	DMA2D->OPFCCR = pix_fmt<<DMA2D_OPFCCR_CM_Pos;
	DMA2D->OCOLR = 0;

	DMA2D->NLR = (sc_result.width<<DMA2D_NLR_PL_Pos) | (sc_result.height<<DMA2D_NLR_NL_Pos);

	bit_mod(DMA2D->CR, DMA2D_CR_MODE_Msk, (2<<DMA2D_CR_MODE_Pos));
	bit_set(DMA2D->CR, DMA2D_CR_START);
}

void draw_string(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *const scissors, const int16_t x, const int16_t y,\
		const font_t *fnt, const char *str )
{
	uint8_t char_width=0;
	int16_t current_x=x;

	while (*str!='\0' && current_x< scissors->x_max)
	{
		const font_char_t *ch = fnt->characters[*str-fnt->offset];
		char_width = ch->padding.left + ch->width + ch->padding.right;
		if(current_x+char_width>scissors->x_min)//draw only chars, that are at least partially visible
		{
			draw_char(FB_addr, pix_fmt, color, scissors, current_x ,y, ch);
		}
		str++;
		current_x+=char_width;
	}
}

//BG = DST
void draw_char(\
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, int16_t x, int16_t y,\
		const font_char_t *ch)
{
	x += ch->padding.left;
	y += ch->padding.top;

	if(ch->width == 0 || ch->height == 0)
		return;

	scissor_result_t sc_result = scissor_area_validate(x, y, ch->width, ch->height, scissors);
	if(!sc_result.valid)
		return;

	int32_t FB_addr_xy = FB_addr+(x+sc_result.x_skipped+(LCD_WIDTH*((uint32_t)y+sc_result.y_skipped)))*pix_fmt_to_size(pix_fmt);//calculate correct start address from DMA using X a Y coordinates
	draw_wait_for_complete();

	DMA2D->FGMAR = (uint32_t)ch->data+sc_result.x_skipped+(sc_result.y_skipped*ch->width) ;
	DMA2D->FGOR = ch->width-sc_result.width;
	DMA2D->FGPFCCR = LCD_PIX_FMT_A8<<DMA2D_FGPFCCR_CM_Pos;
	DMA2D->FGCOLR = lcd_color_to_raw(color, LCD_PIX_FMT_RGB888);

	DMA2D->BGMAR = FB_addr_xy;
	DMA2D->BGOR = (LCD_WIDTH-sc_result.width)<<DMA2D_BGOR_LO_Pos;
	DMA2D->BGPFCCR = pix_fmt<<DMA2D_BGPFCCR_CM_Pos;
	DMA2D->BGCOLR = 0;

	DMA2D->OMAR = FB_addr_xy;
	DMA2D->OOR = (LCD_WIDTH-sc_result.width)<<DMA2D_OOR_LO_Pos;
	DMA2D->OPFCCR = pix_fmt<<DMA2D_OPFCCR_CM_Pos;
	DMA2D->OCOLR = 0;

	DMA2D->NLR = (sc_result.width<<DMA2D_NLR_PL_Pos) | (sc_result.height<<DMA2D_NLR_NL_Pos);

	bit_mod(DMA2D->CR, DMA2D_CR_MODE_Msk, (2<<DMA2D_CR_MODE_Pos));
	bit_set(DMA2D->CR, DMA2D_CR_START);
}


/*
 * @date 25.03.2013
 * @author Armin Joachimsmeyer
 *      Email:   armin.joachimsmeyer@gmail.com
 * @copyright LGPL v3 (http://www.gnu.org/licenses/lgpl.html)
 * @version 1.5.0
 */


/**
 * modified Bresenham with optional overlap (esp. for drawThickLine())
 * Overlap draws additional pixel when changing minor direction - for standard bresenham overlap = LINE_OVERLAP_NONE (0)
 *
 *  Sample line:
 *
 *    00+
 *     -0000+
 *         -0000+
 *             -00
 *
 *  0 pixels are drawn for normal line without any overlap
 *  + pixels are drawn if LINE_OVERLAP_MAJOR
 *  - pixels are drawn if LINE_OVERLAP_MINOR
 */

static void drawLineOverlap(uint32_t FB_addr, lcd_pix_fmt_t pix_fmt, color_t color, const boundaries_t *scissors, int16_t x_start, int16_t y_start,\
	int16_t x_end, int16_t y_end, uint8_t overlap_mode)
{
	scissor_result_t sc_result = scissor_area_validate(x_start, y_start, x_end-x_start, y_end-y_start, scissors);
	if(!sc_result.valid)
		return;
	
	// x_start=x_start+sc_result.x_skipped;
	// y_start=y_start+sc_result.y_skipped;
	// x_end=x_start+sc_result.width;
	// y_end=y_start+sc_result.height;

	int16_t tDeltaX, tDeltaY, tDeltaXTimes2, tDeltaYTimes2, tError, tStepX, tStepY;

	uint32_t color_raw = lcd_color_to_raw(color, pix_fmt);
	uint8_t pix_size = pix_fmt_to_size(pix_fmt);


	if ((x_start == x_end) || (y_start == y_end)) {
		//horizontal or vertical line -> fillRect() is faster
		draw_rectangle_filled(FB_addr, pix_fmt, color, scissors, x_start, y_start, x_end-x_start, y_end-y_start);
	} else {
		//calculate direction
		tDeltaX = x_end - x_start;
		tDeltaY = y_end - y_start;
		if (tDeltaX < 0) {
			tDeltaX = -tDeltaX;
			tStepX = -1;
		} else {
			tStepX = +1;
		}
		if (tDeltaY < 0) {
			tDeltaY = -tDeltaY;
			tStepY = -1;
		} else {
			tStepY = +1;
		}
		tDeltaXTimes2 = tDeltaX << 1;
		tDeltaYTimes2 = tDeltaY << 1;
		//draw start pixel
		draw_point_fast(FB_addr, pix_size, color_raw, x_start, y_start);
		if (tDeltaX > tDeltaY) {
			// start value represents a half step in Y direction
			tError = tDeltaYTimes2 - tDeltaX;
			while (x_start != x_end) {
				// step in main direction
				x_start += tStepX;
				if (tError >= 0) {
					if (overlap_mode & LINE_OVERLAP_MAJOR) {
						// draw pixel in main direction before changing
						draw_point_fast(FB_addr, pix_size, color_raw, x_start, y_start);
					}
					// change Y
					y_start += tStepY;
					if (overlap_mode & LINE_OVERLAP_MINOR) {
						// draw pixel in minor direction before changing
						draw_point_fast(FB_addr, pix_size, color_raw, x_start - tStepX, y_start);
					}
					tError -= tDeltaXTimes2;
				}
				tError += tDeltaYTimes2;
				draw_point_fast(FB_addr, pix_size, color_raw, x_start, y_start);
			}
		} else {
			tError = tDeltaXTimes2 - tDeltaY;
			while (y_start != y_end) {
				y_start += tStepY;
				if (tError >= 0) {
					if (overlap_mode & LINE_OVERLAP_MAJOR) {
						// draw pixel in main direction before changing
						draw_point_fast(FB_addr, pix_size, color_raw, x_start, y_start);
					}
					x_start += tStepX;
					if (overlap_mode & LINE_OVERLAP_MINOR) {
						// draw pixel in minor direction before changing
						draw_point_fast(FB_addr, pix_size, color_raw, x_start, y_start - tStepY);
					}
					tError -= tDeltaYTimes2;
				}
				tError += tDeltaXTimes2;
				draw_point_fast(FB_addr, pix_size, color_raw, x_start, y_start);
			}
		}
	}
}

/**
 * Bresenham with thickness
 * no pixel missed and every pixel only drawn once!
 */
void draw_line(
		const uint32_t FB_addr, const lcd_pix_fmt_t pix_fmt, const color_t color, const boundaries_t *scissors, int16_t x_start, int16_t y_start,\
	int16_t x_end, int16_t y_end, const uint8_t thickness, const uint8_t thickness_mode)
{
	int16_t i, tDeltaX, tDeltaY, tDeltaXTimes2, tDeltaYTimes2, tError, tStepX, tStepY;

	if (thickness <= 1) {
		drawLineOverlap(FB_addr, pix_fmt, color, scissors, x_start, y_start, x_end, y_end, LINE_OVERLAP_NONE);
	}

	scissor_result_t sc_result = scissor_area_validate(x_start, y_start, x_end-x_start, y_end-y_start, scissors);
	if(!sc_result.valid)
		return;
	
	// x_start=x_start+sc_result.x_skipped;
	// y_start=y_start+sc_result.y_skipped;
	// x_end=x_start+sc_result.width;
	// y_end=y_start+sc_result.height;

	/**
	 * For coordinate system with 0.0 top left
	 * Swap X and Y delta and calculate clockwise (new delta X inverted)
	 * or counterclockwise (new delta Y inverted) rectangular direction.
	 * The right rectangular direction for LINE_OVERLAP_MAJOR toggles with each octant
	 */
	tDeltaY = x_end - x_start;
	tDeltaX = y_end - y_start;
	// mirror 4 quadrants to one and adjust deltas and stepping direction
	bool tSwap = true; // count effective mirroring
	if (tDeltaX < 0) {
		tDeltaX = -tDeltaX;
		tStepX = -1;
		tSwap = !tSwap;
	} else {
		tStepX = +1;
	}
	if (tDeltaY < 0) {
		tDeltaY = -tDeltaY;
		tStepY = -1;
		tSwap = !tSwap;
	} else {
		tStepY = +1;
	}
	tDeltaXTimes2 = tDeltaX << 1;
	tDeltaYTimes2 = tDeltaY << 1;
	bool tOverlap;
	// adjust for right direction of thickness from line origin
	int tDrawStartAdjustCount = thickness / 2;
	if (thickness_mode == LINE_THICKNESS_DRAW_COUNTERCLOCKWISE) {
		tDrawStartAdjustCount = thickness - 1;
	} else if (thickness_mode == LINE_THICKNESS_DRAW_CLOCKWISE) {
		tDrawStartAdjustCount = 0;
	}

	// which octant are we now
	if (tDeltaX >= tDeltaY) {
		if (tSwap) {
			tDrawStartAdjustCount = (thickness - 1) - tDrawStartAdjustCount;
			tStepY = -tStepY;
		} else {
			tStepX = -tStepX;
		}
		/*
		 * Vector for draw direction of lines is rectangular and counterclockwise to original line
		 * Therefore no pixel will be missed if LINE_OVERLAP_MAJOR is used
		 * on changing in minor rectangular direction
		 */
		// adjust draw start point
		tError = tDeltaYTimes2 - tDeltaX;
		for (i = tDrawStartAdjustCount; i > 0; i--) {
			// change X (main direction here)
			x_start -= tStepX;
			x_end -= tStepX;
			if (tError >= 0) {
				// change Y
				y_start -= tStepY;
				y_end -= tStepY;
				tError -= tDeltaXTimes2;
			}
			tError += tDeltaYTimes2;
		}
		//draw start line
		drawLineOverlap(FB_addr, pix_fmt, color, scissors ,x_start, y_start, x_end, y_end, LINE_OVERLAP_NONE);
		// draw thickness lines
		tError = tDeltaYTimes2 - tDeltaX;
		for (i = thickness; i > 1; i--) {
			// change X (main direction here)
			x_start += tStepX;
			x_end += tStepX;
			tOverlap = LINE_OVERLAP_NONE;
			if (tError >= 0) {
				// change Y
				y_start += tStepY;
				y_end += tStepY;
				tError -= tDeltaXTimes2;
				/*
				 * change in minor direction reverse to line (main) direction
				 * because of choosing the right (counter)clockwise draw vector
				 * use LINE_OVERLAP_MAJOR to fill all pixel
				 *
				 * EXAMPLE:
				 * 1,2 = Pixel of first lines
				 * 3 = Pixel of third line in normal line mode
				 * - = Pixel which will additionally be drawn in LINE_OVERLAP_MAJOR mode
				 *           33
				 *       3333-22
				 *   3333-222211
				 * 33-22221111
				 *  221111                     /\
				 *  11                          Main direction of draw vector
				 *  -> Line main direction
				 *  <- Minor direction of counterclockwise draw vector
				 */
				tOverlap = LINE_OVERLAP_MAJOR;
			}
			tError += tDeltaYTimes2;
			drawLineOverlap(FB_addr, pix_fmt, color, scissors, x_start, y_start, x_end, y_end, tOverlap);
		}
	} else {
		// the other octant
		if (tSwap) {
			tStepX = -tStepX;
		} else {
			tDrawStartAdjustCount = (thickness - 1) - tDrawStartAdjustCount;
			tStepY = -tStepY;
		}
		// adjust draw start point
		tError = tDeltaXTimes2 - tDeltaY;
		for (i = tDrawStartAdjustCount; i > 0; i--) {
			y_start -= tStepY;
			y_end -= tStepY;
			if (tError >= 0) {
				x_start -= tStepX;
				x_end -= tStepX;
				tError -= tDeltaYTimes2;
			}
			tError += tDeltaXTimes2;
		}
		//draw start line
		drawLineOverlap(FB_addr, pix_fmt, color, scissors ,x_start, y_start, x_end, y_end, LINE_OVERLAP_NONE);
		tError = tDeltaXTimes2 - tDeltaY;
		for (i = thickness; i > 1; i--) {
			y_start += tStepY;
			y_end += tStepY;
			tOverlap = LINE_OVERLAP_NONE;
			if (tError >= 0) {
				x_start += tStepX;
				x_end += tStepX;
				tError -= tDeltaYTimes2;
				tOverlap = LINE_OVERLAP_MAJOR;
			}
			tError += tDeltaXTimes2;
			drawLineOverlap(FB_addr, pix_fmt, color, scissors, x_start, y_start, x_end, y_end, tOverlap);
		}
	}
}
/**
 * The same as before, but no clipping to display range, some pixel are drawn twice (because of using LINE_OVERLAP_BOTH)
 * and direction of thickness changes for each octant (except for LINE_THICKNESS_MIDDLE and thickness value is odd)
 */
// void drawThickLineSimple(unsigned int x_start, unsigned int y_start, unsigned int x_end, unsigned int y_end,
// 		unsigned int thickness, uint8_t thickness_mode, uint16_t aColor) {
// 	int16_t i, tDeltaX, tDeltaY, tDeltaXTimes2, tDeltaYTimes2, tError, tStepX, tStepY;

// 	tDeltaY = x_start - x_end;
// 	tDeltaX = y_end - y_start;
// 	// mirror 4 quadrants to one and adjust deltas and stepping direction
// 	if (tDeltaX < 0) {
// 		tDeltaX = -tDeltaX;
// 		tStepX = -1;
// 	} else {
// 		tStepX = +1;
// 	}
// 	if (tDeltaY < 0) {
// 		tDeltaY = -tDeltaY;
// 		tStepY = -1;
// 	} else {
// 		tStepY = +1;
// 	}
// 	tDeltaXTimes2 = tDeltaX << 1;
// 	tDeltaYTimes2 = tDeltaY << 1;
// 	bool tOverlap;
// 	// which octant are we now
// 	if (tDeltaX > tDeltaY) {
// 		if (thickness_mode == LINE_THICKNESS_MIDDLE) {
// 			// adjust draw start point
// 			tError = tDeltaYTimes2 - tDeltaX;
// 			for (i = thickness / 2; i > 0; i--) {
// 				// change X (main direction here)
// 				x_start -= tStepX;
// 				x_end -= tStepX;
// 				if (tError >= 0) {
// 					// change Y
// 					y_start -= tStepY;
// 					y_end -= tStepY;
// 					tError -= tDeltaXTimes2;
// 				}
// 				tError += tDeltaYTimes2;
// 			}
// 		}
// 		//draw start line
// 		LocalDisplay.drawLine(x_start, y_start, x_end, y_end, aColor);
// 		// draw thickness lines
// 		tError = tDeltaYTimes2 - tDeltaX;
// 		for (i = thickness; i > 1; i--) {
// 			// change X (main direction here)
// 			x_start += tStepX;
// 			x_end += tStepX;
// 			tOverlap = LINE_OVERLAP_NONE;
// 			if (tError >= 0) {
// 				// change Y
// 				y_start += tStepY;
// 				y_end += tStepY;
// 				tError -= tDeltaXTimes2;
// 				tOverlap = LINE_OVERLAP_BOTH;
// 			}
// 			tError += tDeltaYTimes2;
// 			drawLineOverlap(FB_addr, pix_fmt, color, scissors, x_start, y_start, x_end, y_end, tOverlap);
// 		}
// 	} else {
// 		// adjust draw start point
// 		if (thickness_mode == LINE_THICKNESS_MIDDLE) {
// 			tError = tDeltaXTimes2 - tDeltaY;
// 			for (i = thickness / 2; i > 0; i--) {
// 				y_start -= tStepY;
// 				y_end -= tStepY;
// 				if (tError >= 0) {
// 					x_start -= tStepX;
// 					x_end -= tStepX;
// 					tError -= tDeltaYTimes2;
// 				}
// 				tError += tDeltaXTimes2;
// 			}
// 		}
// 		//draw start line
// 		LocalDisplay.drawLine(x_start, y_start, x_end, y_end, aColor);
// 		tError = tDeltaXTimes2 - tDeltaY;
// 		for (i = thickness; i > 1; i--) {
// 			y_start += tStepY;
// 			y_end += tStepY;
// 			tOverlap = LINE_OVERLAP_NONE;
// 			if (tError >= 0) {
// 				x_start += tStepX;
// 				x_end += tStepX;
// 				tError -= tDeltaYTimes2;
// 				tOverlap = LINE_OVERLAP_BOTH;
// 			}
// 			tError += tDeltaXTimes2;
// 			drawLineOverlap(FB_addr, pix_fmt, color, scissors, x_start, y_start, x_end, y_end, tOverlap);
// 		}
// 	}
// }