#ifndef _gui_screen_messages_LIB
	#define _gui_screen_messages_LIB
	
	#include "gui.h"
	#include "nk.h"

	void gui_screen_messages(struct nk_context* ctx, const candb_msg_t  *const *const messages, const uint32_t timestamp);

#endif