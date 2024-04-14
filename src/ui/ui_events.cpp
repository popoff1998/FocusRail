// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: demo5

#include <Arduino.h>
#include "ui.h"
#include "stdio.h"
#include "movement.h"
#include "capture.h"
#include "camera.h	"


void movDistChange(lv_event_t * e)
{
	//Leo el valor del dropDownMovDist
	int indice = lv_dropdown_get_selected(lv_event_get_current_target(e));
	//La almacenamos en la variable global movDistance
	movDistance = movDistances[indice];
}

void movBackward(lv_event_t * e)
{
	//Movemos el motor hacia atrás
	moveMotorDistance(movDistance, BACKWARD);
}

void movForward(lv_event_t * e)
{
	//Movemos el motor hacia adelante
	moveMotorDistance(movDistance, FORWARD);
}

void setCamType(lv_event_t * e)
{
	//Ponemos camType en funcion del dropdown
	camType = lv_dropdown_get_selected(lv_event_get_current_target(e));
	setCamera(camType);
}

void setCamInterface(lv_event_t * e)
{
	// Ponemos camInterface en funcion del dropdown
	camInterface = lv_dropdown_get_selected(lv_event_get_current_target(e));
}

void setCapProf(lv_event_t * e)
{
	// Ponemos capProf en funcion del slider
	capProf = lv_slider_get_value(lv_event_get_current_target(e));
}

void setCapFotos(lv_event_t * e)
{
	// Ponemos capFotos en funcion del slider
	capFotos = lv_slider_get_value(lv_event_get_current_target(e));
}

void setCapTime(lv_event_t * e)
{
	// Ponemos capTime en funcion del slider
	capTime = lv_slider_get_value(lv_event_get_current_target(e));
}

void startCapture(lv_event_t * e)
{
	// Iniciamos la captura de fotos
	capturePhotos();	
}
