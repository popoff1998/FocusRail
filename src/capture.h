//Defines de los pines de control de la cámara
#define CAPTURE_CABLE_PIN 32
#define CAPTURE_IR_PIN 33

//Defines de los tipos de cámara
#define CANON 0
#define NIKON 1

//Defines de las interfaces de la cámara
#define CABLE 0
#define IR 1

//Variables globales
#ifndef CAPTURE_H
#define CAPTURE_H
//Variables para almacenar la configuración de la captura
extern int capProf;
extern int capFotos;
extern int capTime;
//Variables para almacenar la configuración de la camara
extern int camType;
extern int camInterface;
#endif
//Prototipos de las funciones de capture.cpp
void initCapture();
void capturePhoto();
void capturePhotos();

//Fin del archivo capture.h
// Path: src/capture.cpp
