//* Template for using Squareline Studio ui output with
//*   Cheap Yellow Display ("CYD") (aka ESP32-2432S028R)
//* (for example https://www.aliexpress.us/item/3256805998556027.html)
//*
//* 




#include <Arduino.h>
#include <SPI.h>
#include "motor.h "
#include "camera.h"

/*Using LVGL with Arduino requires some extra steps:
 *Be sure to read the docs here: https://docs.lvgl.io/master/get-started/platforms/arduino.html  */

#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"
#include <XPT2046_Touchscreen.h>
// A library for interfacing with the touch screen
//
// Can be installed from the library manager (Search for "XPT2046")
// https://github.com/PaulStoffregen/XPT2046_Touchscreen
// ----------------------------
// Touch Screen pins
// ----------------------------

// The CYD touch uses some non default
// SPI pins

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

// SPIClass mySpi = SPIClass(HSPI); // touch does not work with this setting
SPIClass mySpi = SPIClass(VSPI); // critical to get touch working

XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

/*Change to your screen resolution*/
static const uint16_t screenWidth = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp_drv);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    uint16_t touchX, touchY;

    bool touched = (ts.tirqTouched() && ts.touched()); // this is the version needed for XPT2046 touchscreen

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        // the following three lines are specific for using the XPT2046 touchscreen
        TS_Point p = ts.getPoint();
        touchX = map(p.x, 200, 3700, 1, screenWidth);  /* Touchscreen X calibration */
        touchY = map(p.y, 240, 3800, 1, screenHeight); /* Touchscreen X calibration */
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        //Serial.print("Data x ");
        //Serial.println(touchX);

        //Serial.print("Data y ");
        //Serial.println(touchY);
    }
}

Camera MyCamera;
Motor MyMotor;

void setup()
{
    Serial.begin(115200); /* prepare for possible serial debug */

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println(LVGL_Arduino);
        Serial.println("I am LVGL_Arduino");


        //Inicialización del motor
        MyMotor.initMotor();
        //Inicialización de la camara
        MyCamera.initCamera();

        lv_init();

    #if LV_USE_LOG != 0
        lv_log_register_print_cb(my_print); /* register print function for debugging */
    #endif

        mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); /* Start second SPI bus for touchscreen */
    ts.begin(mySpi);                                                  /* Touchscreen init */
    ts.setRotation(1);                                                /* Landscape orientation */

    tft.begin();        /* TFT init */
    tft.setRotation(1); // Landscape orientation  1 =  CYC usb on right, 2 for vertical

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    /* Uncomment to create simple label */
    // lv_obj_t *label = lv_label_create( lv_scr_act() );
    // lv_label_set_text( label, "Hello Ardino and LVGL!");
    // lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );

    ui_init();

    Serial.println("Setup done");
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}