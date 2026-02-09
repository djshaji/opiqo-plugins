
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"
#include "lv2/lv2plug.in/ns/extensions/ui/ui.h"

#include <cairo.h>

#include "./gx_clubdrive.h"
#include "gui/gx_gui.h"

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
		load png data from binary blob into cairo surface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// png's linked in as binarys
EXTLD(pedal_png)
EXTLD(pswitch_png)
EXTLD(knob_png)
EXTLD(meter_surface_png)
EXTLD(meter_overlay_png)

// read png data from binary blob
cairo_status_t png_stream_reader (void *_stream, unsigned char *data, unsigned int length) {
	binary_stream * stream = (binary_stream *) _stream;
	memcpy(data, &stream->data[stream->position],length);
	stream->position += length;
	return CAIRO_STATUS_SUCCESS;
}

cairo_surface_t *cairo_image_surface_create_from_stream (gx_clubdriveUI* ui, const unsigned char* name) {
	ui->png_stream.data = name;
	ui->png_stream.position = 0;
	return cairo_image_surface_create_from_png_stream(&png_stream_reader, (void *)&ui->png_stream);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				XWindow init the LV2 handle
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// init the xwindow and return the LV2UI handle
static LV2UI_Handle instantiate(const LV2UI_Descriptor * descriptor,
			const char * plugin_uri, const char * bundle_path,
			LV2UI_Write_Function write_function,
			LV2UI_Controller controller, LV2UI_Widget * widget,
			const LV2_Feature * const * features) {

	gx_clubdriveUI* ui = (gx_clubdriveUI*)malloc(sizeof(gx_clubdriveUI));

	if (!ui) {
		fprintf(stderr,"ERROR: failed to instantiate plugin with URI %s\n", plugin_uri);
		return NULL;
	}

	ui->parentWindow = 0;
	LV2UI_Resize* resize = NULL;

	for (int i = 0; features[i]; ++i) {
		if (!strcmp(features[i]->URI, LV2_UI__parent)) {
			ui->parentWindow = features[i]->data;
		} else if (!strcmp(features[i]->URI, LV2_UI__resize)) {
			resize = (LV2UI_Resize*)features[i]->data;
		}
	}

	if (ui->parentWindow == NULL)  {
		fprintf(stderr, "ERROR: Failed to open parentWindow for %s\n", plugin_uri);
		free(ui);
		return NULL;
	}

	if (!gx_gui_open_display(ui)) { // sets ui->dpy (only used by Linux)
		fprintf(stderr, "ERROR: Failed to open display for %s\n", plugin_uri);
		free(ui);
		return NULL;
	}

	ui->controls[0] = (gx_controller) {{1.0, 1.0, 0.0, 1.0, 1.0}, {40, 50, 61, 61}, false,"POWER", BSWITCH, BYPASS};
	ui->controls[1] = (gx_controller) {{0.5, 0.5, 0.0, 1.0, 0.01}, {130, 50, 61, 61}, false,"DRIVE", KNOB, DRIVE};
	ui->controls[2] = (gx_controller) {{0.5, 0.5, 0.0, 1.0, 0.01}, {220, 50, 61, 61}, false,"VOLUME", KNOB, VOLUME};
	ui->controls[3] = (gx_controller) {{-70.0, -70.0, -70.0, 6.0, 0.0001}, {50, 250, 230, 13}, false,"V1", METER, V1};

	ui->block_event = -1;
	ui->start_value = 0.0;
	ui->v1_value = 20.*log10(0.0);;
	ui->sc = NULL;
	ui->set_sc = 0;

	ui->pedal = cairo_image_surface_create_from_stream(ui, LDVAR(pedal_png));
	ui->init_width = cairo_image_surface_get_width(ui->pedal);
	ui->height = ui->init_height = cairo_image_surface_get_height(ui->pedal);
	ui->width = ui->init_width -180 + (70 * CONTROLS);

	gx_gui_create_window_and_surface(ui); // sets ui->win and ui->surface
	ui->cr = cairo_create(ui->surface);

	ui->frame = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 61, 81);
	ui->crf = cairo_create (ui->frame);

	ui->pswitch = cairo_image_surface_create_from_stream(ui, LDVAR(pswitch_png));
	ui->fknob = cairo_image_surface_create_from_stream(ui, LDVAR(knob_png));

	ui->knob_w = cairo_image_surface_get_width (ui->fknob);
	ui->knob_h = cairo_image_surface_get_height (ui->fknob);
    ui->knob_s = (ui->knob_w/ui->knob_h)-1;

	ui->meter_back = cairo_image_surface_create_from_stream(ui, LDVAR(meter_surface_png));
	ui->meter_ahead = cairo_image_surface_create_from_stream(ui, LDVAR(meter_overlay_png));
	ui->meter_state = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 230, 33);
	ui->crm = cairo_create (ui->meter_state);

	*widget = (void*)ui->win;

	ui->blocked = false;
	if (resize){
		ui->resize = resize;
		resize->ui_resize(resize->handle, ui->width, ui->height);
	}

	ui->rescale.x  = (double)ui->width/ui->init_width;
	ui->rescale.y  = (double)ui->height/ui->init_height;
	ui->rescale.x1 = (double)ui->init_width/ui->width;
	ui->rescale.y1 = (double)ui->init_height/ui->height;
	ui->rescale.xc = (double)ui->width/(ui->init_width-180 + (70 * CONTROLS));
	ui->rescale.c = (ui->rescale.xc < ui->rescale.y) ? ui->rescale.xc : ui->rescale.y;
	ui->rescale.x2 =  ui->rescale.xc / ui->rescale.c;
	ui->rescale.y2 = ui->rescale.y / ui->rescale.c;

	gx_gui_register_controller_message(ui); // message for redrawing a controller (only used by Linux)

	ui->controller = controller;
	ui->write_function = write_function;
	//resize_event(ui);

	return (LV2UI_Handle)ui;
}

// cleanup after usage
static void cleanup(LV2UI_Handle handle) {
	gx_clubdriveUI* ui = (gx_clubdriveUI*)handle;
	cairo_destroy(ui->cr);
	cairo_destroy(ui->crf);
	cairo_destroy(ui->crm);
	cairo_surface_destroy(ui->pedal);
	cairo_surface_destroy(ui->pswitch);
	cairo_surface_destroy(ui->fknob);
	cairo_surface_destroy(ui->surface);
	cairo_surface_destroy(ui->frame);
	cairo_surface_destroy(ui->meter_back);
	cairo_surface_destroy(ui->meter_ahead);
	cairo_surface_destroy(ui->meter_state);
	gx_gui_destroy_main_window(ui);
	free(ui);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				XWindow drawing expose handling
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// draw knobs and simple switches
static void knob_expose(gx_clubdriveUI *ui,gx_controller* knob) {
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_CLEAR);
	cairo_paint(ui->crf);
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_OVER);
	//const double scale_zero = 20 * (M_PI/180); // defines "dead zone" for knobs
	//int arc_offset = 0;
	int knob_x = 0;
	int knob_y = 0;
	int w = cairo_image_surface_get_width(ui->frame);
	int h = cairo_image_surface_get_height(ui->frame)-20;
	int grow = (w > h) ? h:w;
	if (knob->type == SWITCH) {
		knob_x = grow-25;
		knob_y = grow-25; 
	} else if (knob->type == ENUM) {
		knob_x = grow-25;
		knob_y = grow-25; 
	} else {
		knob_x = grow-1;
		knob_y = grow-1;
	}
	/** get values for the knob **/

	//int knobx = (w - knob_x) * 0.5;
	int knobx1 = w* 0.5;

	int knoby = (h - knob_y) ;
	int knoby1 = h * 0.5;

	double knobstate = (knob->adj.value - knob->adj.min_value) / (knob->adj.max_value - knob->adj.min_value);
    int findex = (int)(ui->knob_s * knobstate);
    cairo_set_source_surface (ui->crf, ui->fknob, -ui->knob_h*findex, knoby);
	cairo_rectangle(ui->crf,0, knoby, ui->knob_h, ui->knob_h);
	cairo_fill(ui->crf);

	cairo_text_extents_t extents;
	/** show value on the kob**/
	if (knob->type == KNOB && knob->is_active == true) {
		char s[64];
		const char* format[] = {"%.1f", "%.2f", "%.3f"};
		if (fabs(knob->adj.value)>99.99) {
			snprintf(s, 63,"%d",  (int) knob->adj.value);
		} else if (fabs(knob->adj.value)>9.99) {
			snprintf(s, 63, format[1-1], knob->adj.value);
		} else {
			snprintf(s, 63, format[2-1], knob->adj.value);
		}
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
		cairo_set_font_size (ui->crf, 11.0);
		cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
								   CAIRO_FONT_WEIGHT_BOLD);
		cairo_text_extents(ui->crf, "0.00", &extents);
		cairo_move_to (ui->crf, knobx1-extents.width/2, knoby1+extents.height/2);
		cairo_show_text(ui->crf, s);
		cairo_new_path (ui->crf);
	} else if (knob->type == SWITCH) {
		cairo_set_source_rgba (ui->crf, 0.0, 0.0, 0.0,1.0);
		cairo_text_extents(ui->crf,"Off", &extents);
		cairo_move_to (ui->crf, knobx1-knob_x/2.4-extents.width/1.6, knoby1+knob_y/2+extents.height/1.4);
		cairo_show_text(ui->crf, "Off");
		cairo_new_path (ui->crf);

		cairo_text_extents(ui->crf,"On", &extents);
		cairo_move_to (ui->crf, knobx1+knob_x/2.6-extents.width/2.3, knoby1+knob_y/2+extents.height/1.4);
		cairo_show_text(ui->crf, "On");
		cairo_new_path (ui->crf);
	} else if (knob->type == ENUM) {
		cairo_set_source_rgba (ui->crf, 0.0, 0.0, 0.0,1.0);
		cairo_text_extents(ui->crf,"1", &extents);
		cairo_move_to (ui->crf, knobx1-knob_x/2.4-extents.width/1.6, knoby1+knob_y/2+extents.height/1.4);
		cairo_show_text(ui->crf, "1");
		cairo_new_path (ui->crf);

		cairo_text_extents(ui->crf,"2", &extents);
		cairo_move_to (ui->crf, knobx1-extents.width/2, knoby1-knob_y/2-extents.height/2);
		cairo_show_text(ui->crf, "2");
		cairo_new_path (ui->crf);

		cairo_text_extents(ui->crf,"3", &extents);
		cairo_move_to (ui->crf, knobx1+knob_x/2.6-extents.width/2.3, knoby1+knob_y/2+extents.height/1.4);
		cairo_show_text(ui->crf, "3");
		cairo_new_path (ui->crf);
	}
	//cairo_pattern_destroy (pat);

	/** show label below the knob**/
	if (knob->is_active) {
		cairo_set_source_rgba (ui->crf, 0.8, 0.8, 0.8,0.8);
	} else {
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
	}
	cairo_set_font_size (ui->crf, 12.0);
	cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
	cairo_text_extents(ui->crf,knob->label , &extents);

	cairo_move_to (ui->crf, knobx1-extents.width/2, grow+6+extents.height);
	cairo_show_text(ui->crf, knob->label);
	cairo_new_path (ui->crf);
}

// draw the power switch (bypass)
static void bypass_expose(gx_clubdriveUI *ui, gx_controller* switch_) {
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_CLEAR);
	cairo_paint(ui->crf);
	cairo_set_operator(ui->crf,CAIRO_OPERATOR_OVER);

	cairo_set_source_surface (ui->crf, ui->pswitch, -61 * switch_->adj.value, 0);

	//cairo_paint (ui->crf);
	cairo_rectangle(ui->crf,0, 0, 61, 61);
	cairo_fill(ui->crf);
	/** show label below the switch**/
	cairo_text_extents_t extents;

	if (switch_->is_active) {
		cairo_set_source_rgba (ui->crf, 0.8, 0.8, 0.8,0.8);
	} else {
		cairo_set_source_rgba (ui->crf, 0.6, 0.6, 0.6,0.6);
	}
	cairo_set_font_size (ui->crf, 12.0);
	cairo_select_font_face (ui->crf, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
	cairo_text_extents(ui->crf,switch_->label , &extents);

	cairo_move_to (ui->crf, 30.0-extents.width/2, 67.0+extents.height);
	cairo_show_text(ui->crf, switch_->label);
	cairo_new_path (ui->crf);
}

inline double log_meter (double db) {
    float def = 0.0f; /* Meter deflection %age */

    if (db < -70.0f) {
        def = 0.0f;
    } else if (db < -60.0f) {
        def = (db + 70.0f) * 0.25f;
    } else if (db < -50.0f) {
        def = (db + 60.0f) * 0.5f + 2.5f;
    } else if (db < -40.0f) {
        def = (db + 50.0f) * 0.75f + 7.5f;
    } else if (db < -30.0f) {
        def = (db + 40.0f) * 1.5f + 15.0f;
    } else if (db < -20.0f) {
        def = (db + 30.0f) * 2.0f + 30.0f;
    } else if (db < 6.0f) {
        def = (db + 20.0f) * 2.5f + 50.0f;
    } else {
        def = 115.0f;
    }

    /* 115 is the deflection %age that would be
       when db=6.0. this is an arbitrary
       endpoint for our scaling.
    */

    return def/115.0f;
}

static void meter_scale(cairo_t* cr) {
	double x0      = 0;
	double y0      = 0;
	double rect_width  = 230;
	double rect_height = 33;

	int  db_points[] = { -50, -40, -30, -20, -10, -3, 0, 4 };
	char  buf[32];

	cairo_set_font_size (cr, 8.0);
	cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_source_rgba(cr, 0.6, 0.6, 0.6, 0.6);

	for (unsigned int i = 0; i < sizeof (db_points)/sizeof (db_points[0]); ++i)
	{
		float fraction = log_meter(db_points[i]);
		//cairo_set_source_rgb (cr,0.32 + 0.22*i/2,0.5 +  0.1*i/2, 0.1);

		cairo_move_to (cr, x0+(rect_width * fraction),y0+rect_height*0.3);
		cairo_line_to (cr, x0+(rect_width * fraction) ,y0+rect_height*0.6);
		if (i<6)
		{
			snprintf (buf, sizeof (buf), "%d", db_points[i]);
			cairo_move_to (cr, x0+(rect_width * fraction),y0+rect_height*0.28 );
		}
		else
		{
			snprintf (buf, sizeof (buf), " %d", db_points[i]);
			cairo_move_to (cr, x0+(rect_width * fraction),y0+rect_height*0.28 );
		}
		cairo_show_text (cr, buf);
	}

	cairo_set_source_rgba(cr, 0.6, 0.6, 0.6, 0.6);
	cairo_set_line_width(cr, 1.5);
	cairo_stroke(cr);
}

// draw the meter (V)
static void meter_expose(gx_clubdriveUI *ui, gx_controller* meter_) {
	cairo_set_operator(ui->crm,CAIRO_OPERATOR_CLEAR);
	cairo_paint(ui->crm);
	cairo_set_operator(ui->crm,CAIRO_OPERATOR_OVER);
    meter_scale(ui->crm);

	cairo_set_source_surface (ui->crm, ui->meter_back, 0, 15);
	cairo_rectangle(ui->crm,0, 15, 230, 13);
	cairo_fill(ui->crm);
	cairo_set_source_surface (ui->crm, ui->meter_ahead, 0, 15);
    cairo_rectangle(ui->crm,0.0, 15.0, 230.0 * log_meter(meter_->adj.value), 13.0);
    cairo_fill(ui->crm);
    cairo_new_path (ui->crm);
}

// select draw methode by controller type
static void draw_controller(gx_clubdriveUI *ui, gx_controller* controller) {
	if (controller->type == KNOB) knob_expose(ui, controller);
	else if (controller->type == SWITCH) knob_expose(ui, controller);
	else if (controller->type == ENUM) knob_expose(ui, controller);
	else if (controller->type == METER) meter_expose(ui, controller);
	else if (controller->type == BSWITCH) bypass_expose(ui, controller);
}

// general XWindow expose callback, 
void _expose(gx_clubdriveUI *ui) {
	const char* plug_name = "ClubDrive" ;
	cairo_push_group (ui->cr);

	cairo_scale (ui->cr, ui->rescale.x, ui->rescale.y);

	cairo_set_source_surface (ui->cr, ui->pedal, 0, 0);
	cairo_paint (ui->cr);

	cairo_text_extents_t extents;
	cairo_set_source_rgba (ui->cr, 0.6, 0.6, 0.6,0.6);
	cairo_set_font_size (ui->cr, 16.0);
	cairo_select_font_face (ui->cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
							   CAIRO_FONT_WEIGHT_BOLD);
	cairo_text_extents(ui->cr, plug_name, &extents);
	cairo_move_to (ui->cr, ((double)(ui->width/2.0)/ui->rescale.x-(extents.width)/2.0),
	  (double)(ui->height-20.0)/ui->rescale.y-extents.height);
	cairo_show_text(ui->cr, plug_name);

	cairo_scale (ui->cr, ui->rescale.x1, ui->rescale.y1);
	cairo_scale (ui->cr, ui->rescale.c, ui->rescale.c);

	for (int i=0;i<CONTROLS;i++) {
		draw_controller(ui, &ui->controls[i]);
        if (ui->controls[i].type == METER) {
            cairo_set_source_surface (ui->cr, ui->meter_state, 
              (double)ui->controls[i].al.x * ui->rescale.x2,
              (double)ui->controls[i].al.y * ui->rescale.y2);
        } else {
            cairo_set_source_surface (ui->cr, ui->frame, 
		      (double)ui->controls[i].al.x * ui->rescale.x2,
		      (double)ui->controls[i].al.y * ui->rescale.y2);
        } 
		cairo_paint (ui->cr);
	}

	cairo_pop_group_to_source (ui->cr);
	cairo_paint (ui->cr);
}

// redraw a single controller
void controller_expose(gx_clubdriveUI *ui, gx_controller * control) {
	cairo_push_group (ui->cr);
	cairo_scale (ui->cr, ui->rescale.x, ui->rescale.y);

	cairo_set_source_surface (ui->cr, ui->pedal, 0, 0);

	cairo_scale (ui->cr, ui->rescale.x1, ui->rescale.y1);
	cairo_scale (ui->cr, ui->rescale.c, ui->rescale.c);
	cairo_rectangle (ui->cr,(double)control->al.x * ui->rescale.x2,
	  (double)control->al.y * ui->rescale.y2,
	  (double)control->al.width, (double)control->al.height+20.0);
	cairo_fill(ui->cr);
	cairo_stroke(ui->cr);

	draw_controller(ui, control);
    if (control->type == METER) {
        cairo_set_source_surface (ui->cr, ui->meter_state, 
          (double)control->al.x * ui->rescale.x2,
          (double)control->al.y * ui->rescale.y2);
    } else {
        cairo_set_source_surface (ui->cr, ui->frame, 
          (double)control->al.x * ui->rescale.x2,
          (double)control->al.y * ui->rescale.y2);
    }
	cairo_paint (ui->cr);

	cairo_pop_group_to_source (ui->cr);
	cairo_paint (ui->cr);
}

inline float power2db(gx_clubdriveUI *ui,float power) {
    const float falloff = 27 * 60 * 0.0005;
    if (ui->controls[0].adj.value == 0.0) {
        power = 0.0;
    }
    power = 20.*log10(power);
    // retrieve old meter value and consider falloff
    if (power < ui->v1_value) {
        power = max(power, ui->v1_value - falloff);
    }
    
    ui->v1_value = power;
    return  power;
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
				XWindow event handling
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// resize the xwindow and the cairo xlib surface
void resize_event(gx_clubdriveUI *ui) {
	gx_gui_resize_surface(ui);
	ui->rescale.x  = (double)ui->width/ui->init_width;
	ui->rescale.y  = (double)ui->height/ui->init_height;
	ui->rescale.x1 = (double)ui->init_width/ui->width;
	ui->rescale.y1 = (double)ui->init_height/ui->height;
	ui->rescale.xc = (double)ui->width/(ui->init_width-180 + (70 * CONTROLS));
	ui->rescale.c = (ui->rescale.xc < ui->rescale.y) ? ui->rescale.xc : ui->rescale.y;
	ui->rescale.x2 =  ui->rescale.xc / ui->rescale.c;
	ui->rescale.y2 = ui->rescale.y / ui->rescale.c;
}

// send event when active controller changed
static void send_controller_event(gx_clubdriveUI *ui, int controller) {
	gx_gui_send_controller_event(ui, controller);
}

/*------------- check and set state of controllers ---------------*/

// check if controller value changed, if so, redraw
static void check_value_changed(gx_clubdriveUI *ui, int i, float* value) {
	if(fabs(*(value) - ui->controls[i].adj.value)>=0.00001) {
		ui->controls[i].adj.value = *(value);
		if (ui->controls[i].type != METER) {
			if (ui->block_event != ui->controls[i].port)
				ui->write_function(ui->controller,ui->controls[i].port,sizeof(float),0,value);
		}
		send_controller_event(ui, i);
	}
}

// check if controller activation state changed, if so, redraw
static void check_is_active(gx_clubdriveUI *ui, int i, bool set) {
	if (ui->controls[i].is_active != set) {
		ui->controls[i].is_active = set;
		send_controller_event(ui, i);
	}
}

// check if controller is under mouse pointer
static bool aligned(int x, int y, gx_controller *control, gx_clubdriveUI *ui) {
	double ax = (control->al.x * ui->rescale.x2)* ui->rescale.c;
	double ay = (control->al.y  * ui->rescale.y2)* ui->rescale.c;
	double aw = ax + (control->al.width * ui->rescale.c);
	double ah = ay + (control->al.height * ui->rescale.c);
	return ((x >= ax ) && (x <= aw)
	  && (y >= ay ) && (y <= ah)) ? true : false;
}

// get controller number under mouse pointer and make it active, or return false
bool get_active_ctl_num(gx_clubdriveUI *ui, int *num) {
	bool ret = false;
	for (int i=0;i<CONTROLS;i++) {
		if (aligned(ui->pos_x, ui->pos_y, &ui->controls[i], ui)) {
			*(num) = i;
			check_is_active(ui, i, true);
			ret = true;
		} else {
			check_is_active(ui, i, false);
		}
	}
	return ret;
}

// get current active controller number, or return false
static bool get_active_controller_num(gx_clubdriveUI *ui, int *num) {
	for (int i=0;i<CONTROLS;i++) {
		if (ui->controls[i].is_active) {
			*(num) = i;
			return true;
		}
	}
	return false;
}

/*------------- mouse event handlings ---------------*/

// mouse wheel scroll event
void scroll_event(gx_clubdriveUI *ui, int direction) {
	float value;
	int num;
	if (get_active_ctl_num(ui, &num)) {
		value = min(ui->controls[num].adj.max_value,max(ui->controls[num].adj.min_value, 
		  ui->controls[num].adj.value + (ui->controls[num].adj.step * direction)));
		check_value_changed(ui, num, &value);
	}
}

// control is a enum, so switch value
static void enum_event(gx_clubdriveUI *ui, int i) {
	float value;
	if (ui->controls[i].adj.value != ui->controls[i].adj.max_value) {
		value = min(ui->controls[i].adj.max_value,max(ui->controls[i].adj.min_value, 
		  ui->controls[i].adj.value + ui->controls[i].adj.step));
	} else {
		value = ui->controls[i].adj.min_value;
	}
	check_value_changed(ui, i, &value);
}

// control is a switch, so switch value
static void switch_event(gx_clubdriveUI *ui, int i) {
	float value = ui->controls[i].adj.value ? 0.0 : 1.0;
	check_value_changed(ui, i, &value);
}

// left mouse button is pressed, generate a switch event, or set controller active
void button1_event(gx_clubdriveUI *ui, double* start_value) {
	int num;
	if (get_active_ctl_num(ui, &num)) {
		if (ui->controls[num].type == BSWITCH ||ui->controls[num].type == SWITCH) {
			switch_event(ui, num);
		} else if (ui->controls[num].type == ENUM) {
			enum_event(ui, num);
		} else {
			*(start_value) = ui->controls[num].adj.value;
		}
	}
}

// mouse move while left button is pressed
void motion_event(gx_clubdriveUI *ui, double start_value, int m_y) {
	const double scaling = 0.5;
	float value = 0.0;
	int num;
	if (get_active_controller_num(ui, &num)) {
		if (ui->controls[num].type != BSWITCH && ui->controls[num].type != SWITCH && ui->controls[num].type != ENUM) {
			double knobstate = (start_value - ui->controls[num].adj.min_value) /
							   (ui->controls[num].adj.max_value - ui->controls[num].adj.min_value);
			double nsteps = ui->controls[num].adj.step / (ui->controls[num].adj.max_value-ui->controls[num].adj.min_value);
			double nvalue = min(1.0,max(0.0,knobstate + ((double)(ui->pos_y - m_y)*scaling *nsteps)));
			value = nvalue * (ui->controls[num].adj.max_value-ui->controls[num].adj.min_value) + ui->controls[num].adj.min_value;
			check_value_changed(ui, num, &value);
		}
	}
}

/*------------- keyboard event handlings ---------------*/

// set min std or max value, depending on which key is pressed
void set_key_value(gx_clubdriveUI *ui, int set_value) {
	float value = 0.0;
	int num;
	if (get_active_controller_num(ui, &num)) {
		if (set_value == 1) value = ui->controls[num].adj.min_value;
		else if (set_value == 2) value = ui->controls[num].adj.std_value;
		else if (set_value == 3) value = ui->controls[num].adj.max_value;
		check_value_changed(ui, num, &value);
	}
}

// scroll up/down on key's up/right down/left
void key_event(gx_clubdriveUI *ui, int direction) {
	float value;
	int num;
	if (get_active_controller_num(ui, &num)) {
		value = min(ui->controls[num].adj.max_value,max(ui->controls[num].adj.min_value, 
		  ui->controls[num].adj.value + (ui->controls[num].adj.step * direction)));
		check_value_changed(ui, num, &value);
	}
}

// set previous controller active on shift+tab key's
void set_previous_controller_active(gx_clubdriveUI *ui) {
	int num;
	if (get_active_controller_num(ui, &num)) {
		ui->controls[num].is_active = false;
		send_controller_event(ui, num);
		if(num>0) {
			if (ui->controls[num-1].is_active != true) {
				ui->controls[num-1].is_active = true;
				send_controller_event(ui, num-1);
			}
			return;
		} else {
			if (ui->controls[CONTROLS-1].is_active != true) {
				ui->controls[CONTROLS-1].is_active = true;
				send_controller_event(ui, CONTROLS-1);
			}
			return;
		}
	}

	check_is_active(ui, CONTROLS-1, true);
}

// set next controller active on tab key
void set_next_controller_active(gx_clubdriveUI *ui) {
	int num;
	if (get_active_controller_num(ui, &num)) {
		ui->controls[num].is_active = false;
		send_controller_event(ui, num);
		if(num<CONTROLS-1) {
			if (ui->controls[num+1].is_active != true) {
				ui->controls[num+1].is_active = true;
				send_controller_event(ui, num+1);
			}
			return;
		} else {
			if (ui->controls[0].is_active != true) {
				ui->controls[0].is_active = true;
				send_controller_event(ui, 0);
			}
			return;
		}
	}
	check_is_active(ui, 0, true);
}

// get/set active controller on enter and leave notify
void get_last_active_controller(gx_clubdriveUI *ui, bool set) {
	int num;
	if (get_active_controller_num(ui, &num)) {
		ui->sc = &ui->controls[num];
		ui->set_sc = num;
		ui->controls[num].is_active = set;
		send_controller_event(ui, num);
		return;
	} else if (!set) {
		ui->sc =  NULL;
	}
	if (ui->sc != NULL) {
		ui->sc->is_active = true;
		send_controller_event(ui, ui->set_sc);
	}
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------	
						LV2 interface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// port value change message from host
static void port_event(LV2UI_Handle handle, uint32_t port_index,
						uint32_t buffer_size, uint32_t format,
						const void * buffer) {
	gx_clubdriveUI* ui = (gx_clubdriveUI*)handle;
	float value = *(float*)buffer;
	for (int i=0;i<CONTROLS;i++) {
		if (port_index == ui->controls[i].port) {
			if (ui->controls[i].type == METER) {
				value = power2db(ui, *(float*)buffer);
			}
			ui->block_event = (int)port_index;
			check_value_changed(ui, i, &value);
			ui->block_event = -1;
		}
	}
}

// LV2 idle interface to host
static int ui_idle(LV2UI_Handle handle) {
	gx_clubdriveUI* ui = (gx_clubdriveUI*)handle;
	event_handler(ui);
	return 0;
}

// LV2 resize interface to host
static int ui_resize(LV2UI_Feature_Handle handle, int w, int h) {
	gx_clubdriveUI* ui = (gx_clubdriveUI*)handle;
	if (ui) resize_event(ui);
	return 0;
}

// connect idle and resize functions to host
static const void* extension_data(const char* uri) {
	static const LV2UI_Idle_Interface idle = { ui_idle };
	static const LV2UI_Resize resize = { 0 ,ui_resize };
	if (!strcmp(uri, LV2_UI__idleInterface)) {
		return &idle;
	}
	if (!strcmp(uri, LV2_UI__resize)) {
		return &resize;
	}
	return NULL;
}

static const LV2UI_Descriptor descriptor = {
	GXPLUGIN_UI_URI,
	instantiate,
	cleanup,
	port_event,
	extension_data
};


LV2_SYMBOL_EXPORT
const LV2UI_Descriptor* lv2ui_descriptor(uint32_t index) {
	switch (index) {
		case 0:
			return &descriptor;
		default:
		return NULL;
	}
}

