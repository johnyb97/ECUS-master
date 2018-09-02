#ifndef _GUI_LIB
	#define _GUI_LIB

	#include "config.h"
	#include "nk.h"
	#include "ltdc.h"
	#include "candb_structure.h"
	#include "candb_msg.h"

	int8_t gui_menu(struct nk_context* ctx, const float fps);
	void gui_screen_messages(struct nk_context* ctx, const candb_msg_t  *const *const messages, const uint32_t timestamp);
	void gui_draw(struct nk_context* ctx, ltdc_fb_t *fb);
	void gui_clear(ltdc_fb_t *fb);
#endif