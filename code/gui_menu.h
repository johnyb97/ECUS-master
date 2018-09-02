#ifndef _GUI_MENU_LIB
	#define _GUI_MENU_LIB

	#include "misc.h"
	#include "fonts.h"
	#include "icons/icons.h"

	typedef enum{
		MENU_EVT_NONE,
		MENU_EVT_INC,
		MENU_EVT_DEC,
		MENU_EVT_ENTER
	} menu_evt_t;

	struct menu_item_t{
		struct menu_item_t *parent;
		const struct nk_image *icon;
		union{
			struct menu_item_t **submenu_entries;
			void (*oneshot)(void);
			bool (*custom)(struct nk_context* ctx, menu_evt_t event);
		}specific;
		enum{
			MENU_TYPE_SUBMENU,
			MENU_TYPE_ONESHOT,
			MENU_TYPE_CUSTOM,
			MENU_TYPE_EXIT,
		}type;
		const char* name;
	};
	typedef struct menu_item_t menu_item_t;

	typedef struct{
		menu_item_t *volatile current_menu;
		volatile uint8_t selected_position;
		volatile menu_evt_t last_event;
	}menu_t;

	#define MENU_ITEM_EXIT()  (menu_item_t[]){{\
		.parent=NULL,\
		.name="EXIT",\
		.type=MENU_TYPE_EXIT,\
		.icon=&icon_return,\
	}}\

	#define MENU_ITEM_SUBMENU(NAME, ICON, ...) (menu_item_t[]){{\
		.parent=NULL,\
		.name=NAME,\
		.icon=ICON,\
		.type=MENU_TYPE_SUBMENU,\
		.specific.submenu_entries=(menu_item_t*[]){\
			MENU_ITEM_EXIT(),\
			__VA_ARGS__,\
			MENU_ITEM_EXIT(),\
			NULL\
		},\
	}}\

	#define MENU_ITEM_ONESHOT(NAME, ICON, ONESHOT_FCN)  (menu_item_t[]){{\
		.parent=NULL,\
		.name=NAME,\
		.icon=ICON,\
		.type=MENU_TYPE_ONESHOT,\
		.specific.oneshot = ONESHOT_FCN,\
	}}\

	#define MENU_ITEM_CUSTOM(NAME, ICON, CUSTOM_DRAW_FCN)  (menu_item_t[]){{\
		.parent=NULL,\
		.name=NAME,\
		.icon=ICON,\
		.type=MENU_TYPE_CUSTOM,\
		.specific.oneshot = CUSTOM_DRAW_FCN,\
	}}\

	bool gui_menu_event(menu_t *menu, menu_evt_t event);
	void gui_menu_draw(struct nk_context* ctx, menu_t *menu);

#endif