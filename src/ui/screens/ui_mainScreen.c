// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Cheap_Yello_Display_demo

#include "../ui.h"

void ui_mainScreen_screen_init(void)
{
    ui_mainScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_mainScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_mainScreen, lv_color_hex(0x88E8EB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_mainScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_mainScreen);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -1);
    lv_obj_set_y(ui_Label3, -98);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Focus Rail V1.1");

    ui_goConfSc = lv_btn_create(ui_mainScreen);
    lv_obj_set_width(ui_goConfSc, 257);
    lv_obj_set_height(ui_goConfSc, 50);
    lv_obj_set_x(ui_goConfSc, 2);
    lv_obj_set_y(ui_goConfSc, -51);
    lv_obj_set_align(ui_goConfSc, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_goConfSc, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_goConfSc, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label4 = lv_label_create(ui_goConfSc);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 1);
    lv_obj_set_y(ui_Label4, 2);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Configuracion");

    ui_goMovSc = lv_btn_create(ui_mainScreen);
    lv_obj_set_width(ui_goMovSc, 257);
    lv_obj_set_height(ui_goMovSc, 50);
    lv_obj_set_x(ui_goMovSc, 3);
    lv_obj_set_y(ui_goMovSc, 13);
    lv_obj_set_align(ui_goMovSc, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_goMovSc, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_goMovSc, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label5 = lv_label_create(ui_goMovSc);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 1);
    lv_obj_set_y(ui_Label5, 2);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Movimiento");

    ui_goScreen3 = lv_btn_create(ui_mainScreen);
    lv_obj_set_width(ui_goScreen3, 257);
    lv_obj_set_height(ui_goScreen3, 50);
    lv_obj_set_x(ui_goScreen3, 5);
    lv_obj_set_y(ui_goScreen3, 78);
    lv_obj_set_align(ui_goScreen3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_goScreen3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_goScreen3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_goCapSc = lv_label_create(ui_goScreen3);
    lv_obj_set_width(ui_goCapSc, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_goCapSc, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_goCapSc, 1);
    lv_obj_set_y(ui_goCapSc, 2);
    lv_obj_set_align(ui_goCapSc, LV_ALIGN_CENTER);
    lv_label_set_text(ui_goCapSc, "Captura");

    ui_wifiIcon = lv_img_create(ui_mainScreen);
    lv_img_set_src(ui_wifiIcon, &ui_img_wifi32_png);
    lv_obj_set_width(ui_wifiIcon, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_wifiIcon, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_wifiIcon, 732);
    lv_obj_set_y(ui_wifiIcon, -83);
    lv_obj_set_align(ui_wifiIcon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_wifiIcon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_wifiIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_goConfSc, ui_event_goConfSc, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_goMovSc, ui_event_goMovSc, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_goScreen3, ui_event_goScreen3, LV_EVENT_ALL, NULL);

}
