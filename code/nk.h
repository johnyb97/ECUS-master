#ifndef _NK_LIB
	#define _NK_LIB

	#include "config.h"
	#include "nuklear/nuklear.h"

	NK_API void nk_hspacer(const struct nk_context *ctx);
	NK_API int nk_text_wrap_get_height(const struct nk_context *ctx, const char *string);
	NK_API void nk_label_wrap_vertical_hack(struct nk_context *ctx, const char *string);
	NK_API unsigned int nk_get_remaining_vertical_space(struct nk_context *ctx);
	NK_API void nk_filled_color(struct nk_context *ctx, struct nk_color color);
	NK_API void nk_image_color_centered(struct nk_context *ctx, struct nk_image img, struct nk_color col);
#endif