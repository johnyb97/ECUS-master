#ifndef _GUI_VIEW_LIB
	#define _GUI_VIEW_LIB
	
	typedef struct{
		void (*draw)(void);
		const char *name;
	}gui_view_t;
#endif