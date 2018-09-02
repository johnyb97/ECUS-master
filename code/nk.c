#include "fast_math.h"
#include "nk.h"
#define NK_IMPLEMENTATION
#define NK_MEMSET __builtin_memset
#define NK_MEMCPY __builtin_memcpy
#define NK_COS arm_cos_f32   
#define NK_SIN arm_sin_f32
#define NK_SWRT fast_math_sqrt
#include "nuklear/nuklear.h"

#include <limits.h>

NK_API void
nk_hspacer(const struct nk_context *ctx)
{
	struct nk_rect r= nk_rect(0,0,0,0);
	nk_widget(&r,ctx);
}

NK_API int
nk_text_wrap_get_height(const struct nk_context *ctx,
	const char *string)
{
	const struct nk_user_font *f=ctx->style.font;
	struct nk_rect b={.x=0, .y=0, .h=INT_MAX};
	nk_layout_peek(&b, ctx);//sets bounds width
	b.y=0;
	int len = strlen(string);
	float width;
	int glyphs = 0;
	int fitting = 0;
	int done = 0;
	struct nk_rect line;
	struct nk_text t;
	NK_INTERN nk_rune seperator[] = {' '};

	t.padding = ctx->style.text.padding;

	b.w = NK_MAX(b.w, 2 * t.padding.x);
	// b.h = NK_MAX(b.h, 2 * t.padding.y);
	// b.h = b.h - 2 * t.padding.y;

	// line.x = b.x + t.padding.x;
	line.y = b.y + t.padding.y;
	line.w = b.w - 2 * t.padding.x;
	// line.h = 2 * t.padding.y + f->height;

	fitting = nk_text_clamp(f, string, len, line.w, &glyphs, &width, seperator,NK_LEN(seperator));
	while (done < len) {
		if (!fitting) break;
		done += fitting;
		line.y += f->height + 2 * t.padding.y;
		fitting = nk_text_clamp(f, &string[done], len - done, line.w, &glyphs, &width, seperator,NK_LEN(seperator));
	}
	return line.y;
}

NK_API void
nk_label_wrap_vertical_hack(struct nk_context *ctx, const char *string)
{
	uint16_t height=nk_text_wrap_get_height(ctx, string);
	ctx->current->layout->row.height=height+2*(&ctx->style)->window.padding.y;//hack
	nk_label_wrap(ctx, string);

}

NK_API unsigned int
nk_get_remaining_vertical_space(struct nk_context *ctx)
{
	struct nk_panel *layout = ctx->current->layout;
	int height = (layout->bounds.y + layout->bounds.h)-(layout->at_y + layout->row.height + ctx->style.window.spacing.y);
	return max(0, height);
}

NK_API void
nk_filled_color(struct nk_context *ctx, struct nk_color color)
{
    struct nk_window *win;
    struct nk_panel *layout;
    const struct nk_input *in;
    struct nk_style_button button;

    struct nk_rect bounds;
    struct nk_rect content;
    enum nk_widget_layout_states state;

    NK_ASSERT(ctx);
    NK_ASSERT(ctx->current);
    NK_ASSERT(ctx->current->layout);
    if (!ctx || !ctx->current || !ctx->current->layout)
        return;

    win = ctx->current;
    layout = win->layout;

    state = nk_widget(&bounds, ctx);
    if (!state) return;
	bounds.y = layout->at_y;
	bounds.h = layout->row.height;

    nk_fill_rect(&win->buffer, bounds, 0, color);
}

NK_API void
nk_image_color_centered(struct nk_context *ctx, struct nk_image img, struct nk_color col)
{
    struct nk_window *win;
    struct nk_rect bounds;

    NK_ASSERT(ctx);
    NK_ASSERT(ctx->current);
    NK_ASSERT(ctx->current->layout);
    if (!ctx || !ctx->current || !ctx->current->layout) return;

    win = ctx->current;
    if (!nk_widget(&bounds, ctx)) return;

	bounds.y += (bounds.h-img.h)/2;
	bounds.x += (bounds.w-img.w)/2;

    nk_draw_image(&win->buffer, bounds, &img, col);
}