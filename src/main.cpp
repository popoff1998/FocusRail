#define MAIN 1
#include <Arduino.h>
#include <SPI.h>
#include "focusrail.hpp"

/*Using LVGL with Arduino requires some extra steps:
 *Be sure to read the docs here: https://docs.lvgl.io/master/get-started/platforms/arduino.html  */

#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"
#include <XPT2046_Touchscreen.h>

//Includes necesarios para las actualizaciones OTA
#include <WiFi.h>
#include "BasicOTA.hpp"
//Incluimos mDNS para ESP32
#include <ESPmDNS.h>
//Para webserial
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

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
    }
}

BasicOTA OTA;
FocusRail Myfr; 
// Para el servidor web
AsyncWebServer server(80);

void connectWifi()
{
    // Código de inicialización para el wifi
    WiFi.mode(WIFI_STA);
    WiFi.begin(Myfr.getSsid().c_str(), Myfr.getPassword().c_str());
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        #ifdef DEBUG
        Serial.println("Connection Failed!");
        #endif
        Myfr.setWifiConnected(false);
        return;
    }
    
    Myfr.setWifiConnected(true);
    #ifdef DEBUG
        Serial.println("Connected to wifi " + String(Myfr.getSsid()));
    #endif  
}

void initMdns()
{
    // Initialize mDNS
    if (!MDNS.begin(Myfr.getHostname().c_str()))
    { // Set the hostname to "esp32.local"
    #ifdef DEBUG
        Serial.println("Error setting up MDNS responder!");
    #endif
        while (1)
        {
            delay(1000);
        }
    }
    #ifdef DEBUG
    Serial.println("mDNS responder started");
    #endif
}

void initOta()
{
    // Inicialización del servicio OTA
    OTA.setHostname(Myfr.getHostname());
    OTA.begin();
    WebSerial.begin(&server);
    server.begin();
    WebSerial.println("Hello from ESP32");
}

void initDisplay()
{
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
}

void initInput()
{
    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
}

void setup()
{
    Serial.begin(115200); /* prepare for possible serial debug */
    #ifdef DEBUG
    Serial.println("Initializing FocusRail");
    #endif
    // Inicializamos el focusrail
    Myfr.initFocusRail();
    //Conectamos al wifi
    connectWifi();
    //Inicializamos mDNS
    initMdns();
    //Inicializamos OTA
    initOta();
    //Inicialización de la interfaz lvgl
    lv_init();
    //Inicialización del display
    initDisplay();
    //Inicialización del input
    initInput();
    //Inicialización de la interfaz
    ui_init();
    //Activamos o no el icono de wifi
    if(Myfr.isWifiConnected())
    {
        lv_obj_clear_flag(ui_wifiIcon, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_wifiIcon, LV_OBJ_FLAG_HIDDEN);
    }
    #ifdef DEBUG
        Serial.println("FocusRail initialized");
    #endif
}

void loop()
{
    OTA.handle();
    lv_timer_handler();
    delay(5);
}