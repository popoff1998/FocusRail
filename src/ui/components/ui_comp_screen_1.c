// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: demo5

#include "../ui.h"


// COMPONENT Screen 1

lv_obj_t * ui_Screen_1_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Screen_1;
    cui_Screen_1 = lv_btn_create(comp_parent);
    lv_obj_set_width(cui_Screen_1, 100);
    lv_obj_set_height(cui_Screen_1, 62);
    lv_obj_set_align(cui_Screen_1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(cui_Screen_1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_Screen_1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Screen_1, lv_color_hex(0x6492CA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Screen_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Screen_1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Screen_1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Screen_1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Screen_1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SCREEN_1_NUM);
    children[UI_COMP_SCREEN_1_SCREEN_1] = cui_Screen_1;
    lv_obj_add_event_cb(cui_Screen_1, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Screen_1, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Screen_1_create_hook(cui_Screen_1);
    return cui_Screen_1;
}

