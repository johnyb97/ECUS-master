#include "ltdc.h"
#include "debug.h"
#include "debug_enable.h"

#include "gpio.h"



void ltdc_layer_setup(ltdc_layer_t *layer)
{
	// DEBUG_STR("LTDC layer setup\n");
	//no blending or alpha inplemented bro... KISS
	layer->regs->WHPCR = (((LCD_HSYNC)+(LCD_HBP))<<LTDC_LxWHPCR_WHSTPOS_Pos) | (((LCD_HSYNC)+(LCD_HBP)+(LCD_WIDTH)-1)<<LTDC_LxWHPCR_WHSPPOS_Pos);
	layer->regs->WVPCR = (((LCD_VSYNC)+(LCD_VBP))<<LTDC_LxWVPCR_WVSTPOS_Pos) | (((LCD_VSYNC)+(LCD_VBP)+(LCD_HEIGHT)-1)<<LTDC_LxWVPCR_WVSPPOS_Pos);
	layer->regs->PFCR = layer->pix_fmt<<LTDC_LxPFCR_PF_Pos;
	layer->regs->CFBAR = layer->address;
	uint8_t Bpp = pix_fmt_to_size(layer->pix_fmt);
	layer->regs->CFBLR = ((Bpp*(LCD_WIDTH)) <<LTDC_LxCFBLR_CFBP_Pos) | ((Bpp*(LCD_WIDTH)+3) <<LTDC_LxCFBLR_CFBLL_Pos);
	layer->regs->CFBLNR = (LCD_HEIGHT)<<LTDC_LxCFBLNR_CFBLNBR_Pos;
	layer->regs->DCCR = 0xFF<<LTDC_LxDCCR_DCRED_Pos;
	if(layer->enabled)
	{
		bit_set(layer->regs->CR, LTDC_LxCR_LEN);
	}
	else
	{
		bit_clr(layer->regs->CR, LTDC_LxCR_LEN);
	}
}

void ltdc_set_buffer_to_display(ltdc_fb_t *fb)
{
	ltdc_layer_setup(&fb->layer[0]);
	ltdc_layer_setup(&fb->layer[1]);
	LTDC->SRCR = LTDC_SRCR_VBR;
}

void ltdc_start(ltdc_fb_t fb_array[])
{
	DEBUG_STR("LTDC start\n");
	ltdc_fb_t *initial_buffer=NULL;
	for(uint8_t idx=0; idx<LCD_BUFFERS; idx++)//find if there is any buffer already marked as first to be drawn, pick first
	{
		if(initial_buffer == NULL && (fb_array[idx].state == LCD_FB_STATE_DISPLAYING || fb_array[idx].state == LCD_FB_STATE_READY_TO_DISPLAY) )
		{
			initial_buffer = &fb_array[idx];
			initial_buffer->state=LCD_FB_STATE_DISPLAYING;
		}
		else
			fb_array[idx].state = LCD_FB_STATE_READY_TO_DRAW;//mark all other buffers as ready to draw
	}
	if(initial_buffer == NULL)//otherwise pick first
		initial_buffer = &fb_array[0];

	ltdc_set_buffer_to_display(initial_buffer);
	bit_set(LTDC->SRCR, LTDC_SRCR_IMR);//reload registers immediately for first buffer
	bit_set(LTDC->GCR, LTDC_GCR_LTDCEN);
}

void ltdc_init(void)
{
	LTDC->SSCR = (( (LCD_HSYNC)-1 )<<LTDC_SSCR_HSW_Pos) | (( (LCD_VSYNC)-1 )<<LTDC_SSCR_VSH_Pos);
	LTDC->BPCR = (( (LCD_HSYNC)+(LCD_HBP)-1 )<<LTDC_BPCR_AHBP_Pos)							| (( (LCD_VSYNC)+(LCD_VBP)-1 )<<LTDC_BPCR_AVBP_Pos );
	LTDC->AWCR = (( (LCD_HSYNC)+(LCD_HBP)+(LCD_WIDTH)-1 )<<LTDC_AWCR_AAW_Pos)				| (( (LCD_VSYNC)+(LCD_VBP)+(LCD_HEIGHT)-1 )<<LTDC_AWCR_AAH_Pos );
	LTDC->TWCR = (( (LCD_HSYNC)+(LCD_HBP)+(LCD_WIDTH)+(LCD_HFP)-1 )<<LTDC_TWCR_TOTALW_Pos)	| (( (LCD_VSYNC)+(LCD_VBP)+(LCD_HEIGHT)+(LCD_VFP)-1 )<<LTDC_TWCR_TOTALH_Pos );

	// LTDC->GCR = (1<<LTDC_GCR_DEPOL_Pos);//DE active high
	LTDC->BCCR = 0xFF<<LTDC_BCCR_BCRED_Pos;
	LTDC->IER = LTDC_IER_LIE | LTDC_IER_RRIE;
	LTDC->LIPCR = LCD_HEIGHT;
	NVIC_SetPriority(LTDC_IRQn, LTDC_IRQ_PRIORITY);
	NVIC_EnableIRQ(LTDC_IRQn);
}

ltdc_fb_t *ltdc_get_drawable_fb(ltdc_fb_t fb_array[])
{
	for(uint8_t idx=0; idx<LCD_BUFFERS; idx++)
	{
		if(fb_array[idx].state == LCD_FB_STATE_READY_TO_DRAW )//find first FB ready to draw
		{
			return &fb_array[idx];
		}
	}
	return NULL;
}

void ltdc_release_fb_to_display(ltdc_fb_t **fb_ptr)
{
	ltdc_fb_t *temp=*fb_ptr;
	*fb_ptr=NULL;//be rude and set callers pointer to NULL to prevent further ptr usage (C++ has something more suitable, right?)
	// DEBUG_STR("buff release\n");
	temp->state=LCD_FB_STATE_READY_TO_DISPLAY;
}



void LTDC_IRQHandler(void)
{
	// DEBUG_STR("LTDC irq ");
	//set registers to point to buffer wich is ready to draw
	//happens somewhere before end of active area
	if(LTDC->ISR&LTDC_ISR_LIF)
	{
		gpio_set(LED2);
		LTDC->ICR = LTDC_ICR_CLIF;
		// DEBUG_STR("LI\n");
		
		for(uint8_t idx=0; idx<LCD_BUFFERS; idx++)
		{
			if(lcd_fb[idx].state == LCD_FB_STATE_READY_TO_DISPLAY )//find FB ready to display
			{
				// DEBUG_STR("buff rdy ");
				// DEBUG_NUM(idx,1);
				// DEBUG_NL();
				ltdc_set_buffer_to_display(&lcd_fb[idx]);
				break;
			}
		}
		gpio_clr(LED2);
	}

	//release fb to draw, mark fb that is ready to display as being displayed (will be in next frame) 
	//happens right after leaving active area
	if(LTDC->ISR&LTDC_ISR_RRIF)
	{
		gpio_set(LED3);
		// DEBUG_STR("RRI\n");
		LTDC->ICR = LTDC_ICR_CRRIF;
		for(uint8_t i=0; i<LCD_BUFFERS; i++)
		{
			if(lcd_fb[i].state == LCD_FB_STATE_READY_TO_DISPLAY)//if there is any new buffer to draw
			{
				for(uint8_t idx=0; idx<LCD_BUFFERS; idx++)
				{
					switch(lcd_fb[idx].state)
					{
						//release FB which was drawn
						case LCD_FB_STATE_DISPLAYING:
							lcd_fb[idx].state = LCD_FB_STATE_READY_TO_DRAW;
							// DEBUG_STR("LCD FB rls: ");
							// DEBUG_NUM(idx, 1);
							// DEBUG_NL();
							break;
						
						case LCD_FB_STATE_READY_TO_DISPLAY:
							lcd_fb[idx].state = LCD_FB_STATE_DISPLAYING;
							// DEBUG_STR("LCD FB draw: ");
							// DEBUG_NUM(idx, 1);
							// DEBUG_NL();
							break;
						
						default:
							// DEBUG_STR("LCD FB ign: ");
							// DEBUG_NUM(idx, 1);
							// DEBUG_NL();
							break;
							
					}

				}
				break;
			}
		}
		gpio_clr(LED3);
	}

}