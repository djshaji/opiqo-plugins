// vim:ts=4:sw=4:noet:
#ifndef __GX_PLATFORM_APPLE_H__
#define __GX_PLATFORM_APPLE_H__ 1
#ifdef __APPLE__ 

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"
#include "lv2/lv2plug.in/ns/extensions/ui/ui.h"

#include <cairo-quartz.h>

#include <gui/gx_gui.h>

/*---------------------------------------------------------------------
-----------------------------------------------------------------------
			common functions (required)
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// example: https://cairo.cairographics.narkive.com/I86TGEQq/osx-os-x-example#post7

bool gx_gui_open_display(gx_eternityUI *ui) {
	return true; // STUB
}

void gx_gui_create_window_and_surface(gx_eternityUI *ui) {
	// STUB
}

void gx_gui_register_controller_message(gx_eternityUI *ui) {
	// STUB
}

void gx_gui_destroy_main_window(gx_eternityUI *ui) {
	// STUB
}

void gx_gui_resize_surface(gx_eternityUI *ui) {
	// STUB
}

void gx_gui_send_controller_event(gx_eternityUI *ui, int controller) {
	// STUB
}

#endif /* __APPLE __ */
#endif /* __GX_PLATFORM_APPLE_H__ */
