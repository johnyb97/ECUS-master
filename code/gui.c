#include "gui.h"
#include "debug.h"
#include "math.h"

#include "debug_enable.h"


int8_t gui_menu(struct nk_context* ctx, const float fps)
{
	uint8_t btn=0;
	nk_menubar_begin(ctx);

	/* menu #1 */
	nk_layout_row_template_begin(ctx, 60);
	nk_layout_row_template_push_static(ctx, 120);
	nk_layout_row_template_push_dynamic(ctx);
	// nk_layout_row_template_push_dynamic(ctx);
	// nk_layout_row_template_push_variable(ctx, 120);
	nk_layout_row_template_push_static(ctx, 120);
	nk_layout_row_template_end(ctx);

	if(nk_button_label(ctx, "canalyzer"))
		btn=1;

	if(nk_button_label(ctx, "dummy"))
		btn=2;

	if(nk_button_label(ctx, "tracker"))
		btn=3;

	nk_layout_row_dynamic(ctx, 30, 2);
	nk_label(ctx, "name", NK_TEXT_CENTERED);
	char buffer[16];
	nk_label(ctx, ftoa(buffer, fps, 4, 1, ' '), NK_TEXT_CENTERED);


	// nk_layout_row_begin(ctx, NK_STATIC, 50, 5);
	// nk_layout_row_push(ctx, 45);
	// if (nk_menu_begin_label(ctx, "MENU", NK_TEXT_LEFT, nk_vec2(120, 200)))
	// {
	// 	static size_t prog = 40;
	// 	static int slider = 10;
	// 	static int check = nk_true;
	// 	nk_layout_row_dynamic(ctx, 25, 1);
	// 	nk_progress(ctx, &prog, 100, NK_MODIFIABLE);
	// 	nk_slider_int(ctx, 0, &slider, 16, 1);
	// 	nk_checkbox_label(ctx, "check", &check);
	// 	nk_menu_end(ctx);
	// }
	
	// /* menu widgets */
	// nk_layout_row_push(ctx, 70);
	// nk_progress(ctx, &mprog, 100, NK_MODIFIABLE);
	// nk_slider_int(ctx, 0, &mslider, 16, 1);
	// nk_checkbox_label(ctx, "check", &mcheck);

	nk_menubar_end(ctx);
	return btn;
}

void gui_clear(ltdc_fb_t *fb)
{
	if(fb->layer[0].enabled)
		draw_rectangle_filled(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR(255,255,255), NULL, 0, 0, LCD_WIDTH, LCD_HEIGHT);
		
	if(fb->layer[1].enabled)
		draw_rectangle_filled(fb->layer[1].address, fb->layer[1].pix_fmt, LCD_COLOR(255,255,255), NULL, 0, 0, LCD_WIDTH, LCD_HEIGHT);
}

void gui_draw(struct nk_context* ctx, ltdc_fb_t *fb)
{
	boundaries_t scissors={.x_min=0, .y_min=0, .x_max=LCD_WIDTH, .y_max=LCD_HEIGHT};
	const struct nk_command *cmd = 0;

	nk_foreach(cmd, ctx) {
		switch (cmd->type) {
			case NK_COMMAND_NOP: break;
			// DEBUG_STR("NOP\n");
			case NK_COMMAND_SCISSOR: {
				// DEBUG_STR("SCISSOR\n");
				const struct nk_command_scissor *s = (const struct nk_command_scissor*)cmd;
				scissors.x_min = max(s->x, 0);
				scissors.x_max = min(s->x + s->w, LCD_WIDTH);
				scissors.y_min = max(s->y, 0);
				scissors.y_max = min(s->y + s->h, LCD_HEIGHT);
			} break;
			case NK_COMMAND_LINE: {
				// DEBUG_STR("LINE\n");
				const struct nk_command_line *l = (const struct nk_command_line*)cmd;
				draw_line(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(l->color.r, l->color.g, l->color.b, l->color.a), &scissors, l->begin.x, l->begin.y, l->end.x, l->end.y, l->line_thickness, LINE_THICKNESS_MIDDLE);
			} break;
			case NK_COMMAND_CURVE: {
				DEBUG_STR("CURVE\n");
					// const struct nk_command_curve *q = (const struct nk_command_curve*)cmd;
				// nk_draw_list_stroke_curve(ctx->draw_list, nk_vec2(q->begin.x, q->begin.y),
				// 	nk_vec2(q->ctrl[0].x, q->ctrl[0].y), nk_vec2(q->ctrl[1].x,
				// 	q->ctrl[1].y), nk_vec2(q->end.x, q->end.y), q->color,
				// 	config->curve_segment_count, q->line_thickness);
			} break;
			case NK_COMMAND_RECT: {
				// DEBUG_STR("RECT\n");
				const struct nk_command_rect *r = (const struct nk_command_rect*)cmd;
				if(r->line_thickness>=1)
					draw_rectangle(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(r->color.r, r->color.g, r->color.b, r->color.a), &scissors, r->x, r->y, r->w, r->h, r->line_thickness);
			} break;
			case NK_COMMAND_RECT_FILLED: {
				// DEBUG_STR("RECT_FILLED\n");
				const struct nk_command_rect_filled *r = (const struct nk_command_rect_filled*)cmd;
				if(r->rounding<=1)
					draw_rectangle_filled(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(r->color.r, r->color.g, r->color.b, r->color.a), &scissors, r->x, r->y, r->w, r->h);
				else
					draw_rectangle_filled_rounded(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(r->color.r, r->color.g, r->color.b, r->color.a), &scissors, r->x, r->y, r->w, r->h, r->rounding);
			} break;
			case NK_COMMAND_RECT_MULTI_COLOR: {
				DEBUG_STR("RECT_MULTI_COLOR\n");
					// const struct nk_command_rect_multi_color *r = (const struct nk_command_rect_multi_color*)cmd;
				// nk_draw_list_fill_rect_multi_color(ctx->draw_list, nk_rect(r->x, r->y, r->w, r->h),
					// r->left, r->top, r->right, r->bottom);
			} break;
			case NK_COMMAND_CIRCLE: {
				DEBUG_STR("CIRCLE\n");
					// const struct nk_command_circle *c = (const struct nk_command_circle*)cmd;
				// nk_draw_list_stroke_circle(ctx->draw_list, nk_vec2((float)c->x + (float)c->w/2,
					// (float)c->y + (float)c->h/2), (float)c->w/2, c->color,
					// config->circle_segment_count, c->line_thickness);
			} break;
			case NK_COMMAND_CIRCLE_FILLED: {
				// DEBUG_STR("CIRCLE_FILLED\n");
				const struct nk_command_circle_filled *c = (const struct nk_command_circle_filled *)cmd;
				// draw_circle_filled(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(c->color.r, c->color.g, c->color.b, c->color.a), &scissors, c->x+c->w/2, c->y+c->h/2, c->h/2);
				draw_rectangle_filled_rounded(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(c->color.r, c->color.g, c->color.b, c->color.a), &scissors, c->x, c->y, c->w, c->h, c->w/2);
			} break;
			case NK_COMMAND_ARC: {
				DEBUG_STR("ARC\n");
					// const struct nk_command_arc *c = (const struct nk_command_arc*)cmd;
				// nk_draw_list_path_line_to(ctx->draw_list, nk_vec2(c->cx, c->cy));
				// nk_draw_list_path_arc_to(ctx->draw_list, nk_vec2(c->cx, c->cy), c->r,
					// c->a[0], c->a[1], config->arc_segment_count);
				// nk_draw_list_path_stroke(ctx->draw_list, c->color, NK_STROKE_CLOSED, c->line_thickness);
			} break;
			case NK_COMMAND_ARC_FILLED: {
				DEBUG_STR("ARC_FILLED\n");
					// const struct nk_command_arc_filled *c = (const struct nk_command_arc_filled*)cmd;
				// nk_draw_list_path_line_to(ctx->draw_list, nk_vec2(c->cx, c->cy));
				// nk_draw_list_path_arc_to(ctx->draw_list, nk_vec2(c->cx, c->cy), c->r,
				// 	c->a[0], c->a[1], config->arc_segment_count);
				// nk_draw_list_path_fill(ctx->draw_list, c->color);
			} break;
			case NK_COMMAND_TRIANGLE: {
				DEBUG_STR("TRIANGLE\n");
					// const struct nk_command_triangle *t = (const struct nk_command_triangle*)cmd;
				// nk_draw_list_stroke_triangle(ctx->draw_list, nk_vec2(t->a.x, t->a.y),
				// 	nk_vec2(t->b.x, t->b.y), nk_vec2(t->c.x, t->c.y), t->color,
				// 	t->line_thickness);
			} break;
			case NK_COMMAND_TRIANGLE_FILLED: {
				DEBUG_STR("TRIANGLE_FILLED\n");
					// const struct nk_command_triangle_filled *t = (const struct nk_command_triangle_filled*)cmd;
				// nk_draw_list_fill_triangle(ctx->draw_list, nk_vec2(t->a.x, t->a.y),
				// 	nk_vec2(t->b.x, t->b.y), nk_vec2(t->c.x, t->c.y), t->color);
			} break;
			case NK_COMMAND_POLYGON: {
				DEBUG_STR("POLYGON\n");
				// int i;
					// const struct nk_command_polygon*p = (const struct nk_command_polygon*)cmd;
				// for (i = 0; i < p->point_count; ++i) {
				// 	struct nk_vec2 pnt = nk_vec2((float)p->points[i].x, (float)p->points[i].y);
				// 	nk_draw_list_path_line_to(ctx->draw_list, pnt);
				// }
				// nk_draw_list_path_stroke(ctx->draw_list, p->color, NK_STROKE_CLOSED, p->line_thickness);
			} break;
			case NK_COMMAND_POLYGON_FILLED: {
				DEBUG_STR("POLYGON_FILLED\n");
				// int i;
					// const struct nk_command_polygon_filled *p = (const struct nk_command_polygon_filled*)cmd;
				// for (i = 0; i < p->point_count; ++i) {
					// struct nk_vec2 pnt = nk_vec2((float)p->points[i].x, (float)p->points[i].y);
					// nk_draw_list_path_line_to(ctx->draw_list, pnt);
				// }
				// nk_draw_list_path_fill(ctx->draw_list, p->color);
			} break;
			case NK_COMMAND_POLYLINE: {
				DEBUG_STR("POLYLINE\n");
				const struct nk_command_polyline *p = (const struct nk_command_polyline*)cmd;
				for (uint16_t  i = 0; i < p->point_count-1; ++i) {
					draw_line(	fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(p->color.r, p->color.g, p->color.b, p->color.a), &scissors, p->points[i].x, p->points[i].y,\
								p->points[i+1].x, p->points[i+1].y, p->line_thickness, LINE_THICKNESS_MIDDLE);

				}
			} break;
			case NK_COMMAND_TEXT: {
				// DEBUG_STR("TEXT\n");
				const struct nk_command_text *t = (const struct nk_command_text*)cmd;
				draw_string(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR_A(t->foreground.r, t->foreground.g, t->foreground.b, t->foreground.a), &scissors, t->x, t->y,\
				t->font->userdata.ptr, t->string);
			} break;
			case NK_COMMAND_IMAGE: {
				const struct nk_command_image *i = (const struct nk_command_image*)cmd;
				draw_bitmap(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR(i->col.r, i->col.g, i->col.b), &scissors, i->x, i->y, LCD_PIX_FMT_A8, i->img.handle.ptr, i->img.w, i->img.h);
			} break;
			case NK_COMMAND_CUSTOM: {
				DEBUG_STR("CUSTOM\n");
					// const struct nk_command_custom *c = (const struct nk_command_custom*)cmd;
				// c->callback(ctx->draw_list, c->x, c->y, c->w, c->h, c->callback_data);
			} break;
			default: break;
		}							
	}
	draw_wait_for_complete();
}