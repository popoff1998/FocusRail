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
#include "ui_events.h"

void bouncingball_Animation(lv_obj_t * TargetObject, int delay);
void takeFoto_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_mainScreen
void ui_mainScreen_screen_init(void);
extern lv_obj_t * ui_mainScreen;
extern lv_obj_t * ui_Label3;
void ui_event_goConfSc(lv_event_t * e);
extern lv_obj_t * ui_goConfSc;
extern lv_obj_t * ui_Label4;
void ui_event_goMovSc(lv_event_t * e);
extern lv_obj_t * ui_goMovSc;
extern lv_obj_t * ui_Label5;
void ui_event_goScreen3(lv_event_t * e);
extern lv_obj_t * ui_goScreen3;
extern lv_obj_t * ui_goCapSc;
// SCREEN: ui_confScreen
void ui_confScreen_screen_init(void);
extern lv_obj_t * ui_confScreen;
void ui_event_ImgButton1(lv_event_t * e);
extern lv_obj_t * ui_ImgButton1;
extern lv_obj_t * ui_Label1;
void ui_event_camType(lv_event_t * e);
extern lv_obj_t * ui_camType;
void ui_event_interfaceType(lv_event_t * e);
extern lv_obj_t * ui_interfaceType;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_defFotosLabel;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_defProfLabel;
void ui_event_Slider2(lv_event_t * e);
extern lv_obj_t * ui_Slider2;
void ui_event_Slider3(lv_event_t * e);
extern lv_obj_t * ui_Slider3;
// SCREEN: ui_movScreen
void ui_movScreen_screen_init(void);
extern lv_obj_t * ui_movScreen;
void ui_event_ImgButton2(lv_event_t * e);
extern lv_obj_t * ui_ImgButton2;
extern lv_obj_t * ui_Label7;
void ui_event_dropDownDistMov(lv_event_t * e);
extern lv_obj_t * ui_dropDownDistMov;
extern lv_obj_t * ui_Label9;
void ui_event_ImgButton4(lv_event_t * e);
extern lv_obj_t * ui_ImgButton4;
void ui_event_ImgButton5(lv_event_t * e);
extern lv_obj_t * ui_ImgButton5;
extern lv_obj_t * ui_movLabel;
void ui_event_ImgButton6(lv_event_t * e);
extern lv_obj_t * ui_ImgButton6;
// SCREEN: ui_captScreen
void ui_captScreen_screen_init(void);
extern lv_obj_t * ui_captScreen;
void ui_event_ImgButton3(lv_event_t * e);
extern lv_obj_t * ui_ImgButton3;
extern lv_obj_t * ui_Label10;
extern lv_obj_t * ui_Label11;
extern lv_obj_t * ui_Label12;
extern lv_obj_t * ui_capProfLabel;
extern lv_obj_t * ui_capFotLabel;
extern lv_obj_t * ui_capTimeLabel;
void ui_event_capProfSlider(lv_event_t * e);
extern lv_obj_t * ui_capProfSlider;
void ui_event_capFtoSlider(lv_event_t * e);
extern lv_obj_t * ui_capFtoSlider;
void ui_event_capTimeSlider(lv_event_t * e);
extern lv_obj_t * ui_capTimeSlider;
void ui_event_startButton(lv_event_t * e);
extern lv_obj_t * ui_startButton;
extern lv_obj_t * ui_Label13;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_home_png);    // assets/home.png
LV_IMG_DECLARE(ui_img_388382192);    // assets/left-arrow.png
LV_IMG_DECLARE(ui_img_1101766569);    // assets/right-arrow.png
LV_IMG_DECLARE(ui_img_885855874);    // assets/stop-button.png






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
