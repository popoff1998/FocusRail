// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Cheap_Yello_Display_demo

#include "../ui.h"

void ui_updateScreen_screen_init(void)
{
    ui_updateScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_updateScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_updateScreen, lv_color_hex(0x8BEAEE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_updateScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_updateScreen);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, 1);
    lv_obj_set_y(ui_Label14, -64);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "Actualizando");

    ui_updateBar = lv_bar_create(ui_updateScreen);
    lv_bar_set_value(ui_updateBar, 25, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_updateBar, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_updateBar, 247);
    lv_obj_set_height(ui_updateBar, 42);
    lv_obj_set_x(ui_updateBar, 2);
    lv_obj_set_y(ui_updateBar, -3);
    lv_obj_set_align(ui_updateBar, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_updateScreen, ui_event_updateScreen, LV_EVENT_ALL, NULL);

}
