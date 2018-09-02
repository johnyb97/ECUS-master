#include "fonts.h"

float text_width_calculate(nk_handle handle, float height, const char *text, int len)
{
	UNUSED(height);
	font_t *fnt = (font_t*)handle.ptr;
	uint32_t length=0;
	for(uint16_t ch=0; ch<len; ch++)
	{
		const font_char_t *character = fnt->characters[text[ch]-fnt->offset];
		length += character->width + character->padding.left + character->padding.right;
	}
	return length+1;//A4 encoded text might be 1px longer
}

struct nk_user_font font_nk_default = {
	.userdata.ptr = (void*)&font_ecus_font_default,
	.height = 30,
	.width = text_width_calculate,
};

struct nk_user_font font_nk_large = {
	.userdata.ptr = (void*)&font_ecus_font_large,
	.height = 59,
	.width = text_width_calculate,
};

