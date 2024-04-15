#pragma once

#include "MD_multiCameraIrControl.h"

// Defines de los pines de control de la cámara
#define CAMERA_CABLE_PIN 32
#define CAMERA_IR_PIN 33
#define CAPTURE_CABLE_PIN 34

class Camera
{
    public:
        //Metodos de la clase Camera
        Camera() {};
        void initCamera();
        void setCamera(int);
		void setInterface(int);
        void capturePhoto();
        void capturePhotos();
		void captureByIR();
		void setCameraIR(int);
		void captureByCable();
        //Variables de la clase Camera
        int camType;
        int camInterface;
        int capProf;
        int capFotos;
        int capTime;
        cCamera* irInterface;
};


//Fin del archivo configuration.h
// Path: src/configuration.cpp


