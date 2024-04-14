//Variables globales
#ifndef CAPTURE_H
#define CAPTURE_H
//Variables para almacenar la configuración de la captura
extern int capProf;
extern int capFotos;
extern int capTime;
//Variables para almacenar la configuración de la camara
//extern int camType;
//extern int camInterface;
#endif
//Prototipos de las funciones de capture.cpp
void initCapture();
void capturePhoto();
void capturePhotos();

//Fin del archivo capture.h
// Path: src/capture.cpp
