// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: Cheap_Yello_Display_demo

#ifndef _CHEAP_YELLO_DISPLAY_DEMO_UI_H
#define _CHEAP_YELLO_DISPLAY_DEMO_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"

void bouncingball_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
void ui_event_Screen1(lv_event_t * e);
extern lv_obj_t * ui_Screen1;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label1;
void ui_event_Panel1(lv_event_t * e);
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_TextArea1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui____initial_actions0;








void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
