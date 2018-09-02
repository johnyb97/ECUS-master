#ifndef _FONT_LIB
	#define _FONT_LIB
	#include "config.h"

	#include "font_types.h"
	#include "nk.h"

	extern const font_t font_ecus_font_large;
	extern const font_t font_ecus_font_default;

	float text_width_calculate(nk_handle handle, float height, const char *text, int len);

	extern struct nk_user_font font_nk_default;
	extern struct nk_user_font font_nk_large;

#endif