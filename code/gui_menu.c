#include "gui_menu.h"
#include "debug.h"

#include "debug_enable.h"

//returns false, when menu was exited
bool gui_menu_item_enter(menu_t *menu)
{
	menu_item_t *selected_item = menu->current_menu->specific.submenu_entries[menu->selected_position];

	switch(selected_item->type)
	{
		case MENU_TYPE_ONESHOT:
			if(selected_item->specific.oneshot != NULL)
				selected_item->specific.oneshot();
			break;
		
		case MENU_TYPE_EXIT:
			if(menu->current_menu->parent != NULL)
			{
				DEBUG_STR("\nCURRENT: ");
				DEBUG_STR(menu->current_menu->name);
				DEBUG_STR("\nPARENT: ");
				DEBUG_STR(menu->current_menu->parent->name);
				DEBUG_NL();
				menu->current_menu = menu->current_menu->parent;
				menu->selected_position = 0;
			}
			else
				return false;
			break;
		
		default:
		{
			menu_item_t *parent = menu->current_menu;
			menu->current_menu = selected_item;
			menu->current_menu->parent = parent;
			menu->selected_position = 0;
		}
		break;
	}
	return true;
}


void gui_menu_inc(menu_t *menu)
{
	if(menu->current_menu->type == MENU_TYPE_SUBMENU)
	{
		if(menu->current_menu->specific.submenu_entries[menu->selected_position+1] != NULL)
			menu->selected_position++;
	}
}

void gui_menu_dec(menu_t *menu)
{
	if(menu->current_menu->type == MENU_TYPE_SUBMENU)
	{
		if(menu->selected_position > 0)
			menu->selected_position--;
	}
}

bool gui_menu_event(menu_t *menu, menu_evt_t event)
{

	switch(event)
	{
		case MENU_EVT_ENTER:
			return gui_menu_item_enter(menu);

		case MENU_EVT_INC:
			gui_menu_inc(menu);
			break;

		case MENU_EVT_DEC:
			gui_menu_dec(menu);
			break;	
		
		default:
			break;
	}
	return true;
}

void gui_menu_draw(struct nk_context* ctx, menu_t *menu)
{
	menu_item_t *current_menu = menu->current_menu;

	switch(current_menu->type)
	{
		case MENU_TYPE_SUBMENU:
		{

			nk_style_push_font(ctx, &font_nk_large);
			nk_layout_row_dynamic(ctx, 0, 1);
			nk_label(ctx, current_menu->name, NK_TEXT_CENTERED);

			nk_layout_row_dynamic(ctx, -1, 1);
			nk_filled_color(ctx, ctx->style.button.normal.data.color);

			nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx), 1);
			if(nk_group_begin(ctx,"menu_items", 0))
			{
				const uint8_t row_height=70;
				nk_layout_row_template_begin(ctx, row_height);
				nk_layout_row_template_push_static(ctx, 10);//spacer
				nk_layout_row_template_push_static(ctx, row_height);//icon 1:1 aspect ratio
				nk_layout_row_template_push_static(ctx, 10);//spacer
				nk_layout_row_template_push_dynamic(ctx);//entry name
				nk_layout_row_template_push_static(ctx, 10);//spacer
				nk_layout_row_template_end(ctx);

				menu_item_t **menu_entry = current_menu->specific.submenu_entries;
				while(*menu_entry != NULL && nk_get_remaining_vertical_space(ctx)>=row_height)
				{
					nk_hspacer(ctx);
					if((*menu_entry)->icon != NULL)
						nk_image_color_centered(ctx, *(*menu_entry)->icon, ctx->style.text.color);
					else
						nk_hspacer(ctx);	
					nk_hspacer(ctx);
					if(*menu_entry == current_menu->specific.submenu_entries[menu->selected_position])
						nk_label_colored(ctx, (*menu_entry)->name, NK_TEXT_LEFT, ctx->style.button.normal.data.color);
					else
						nk_label(ctx, (*menu_entry)->name, NK_TEXT_LEFT);
					nk_hspacer(ctx);

					menu_entry++;
				}
				nk_group_end(ctx);
			}
			nk_style_pop_font(ctx);
		}
		break;
		
		case MENU_TYPE_CUSTOM:
			if(!current_menu->specific.custom(ctx, menu->last_event))
			{
				//leave custom menu when draw fcn return false
				menu->current_menu = menu->current_menu->parent;
				menu->selected_position = 0;
			}
			break;
		
		default:
			DEBUG_CRITICAL_STR("ERR: MENU not drawable type!");
			break;

	}
	menu->last_event = MENU_EVT_NONE;
}