//Incluimos multicamera.h
#include "MD_multiCameraIrControl.h"

// Defines de los tipos de cámara
#define CANON 0
#define NIKON 1
#define OLYMPUS 2
#define PENTAX 3
#define SONY 4
#define MINOLTA 5

// Defines de las interfaces de la cámara
#define CABLE 0
#define IR 1

//Variables globales
#ifndef CONFIGURATION_H
#define CONFIGURATION_H
//Variable Camera
extern cCamera *camera;
#endif

//Prototipos de las funciones de configuration.cpp




