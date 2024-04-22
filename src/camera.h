#pragma once

#include "MD_multiCameraIrControl.h"

// Defines de los pines de control de la cámara
#define CAMERA_CABLE_PIN 16
#define CAMERA_IR_PIN 17

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
		void setCameraIR(int);
        //Variables de la clase Camera
        int camType;
        int camInterface;
        int capProf;
        int capFotos;
        int capTime;
    private:    
        cCamera* irInterface;
		void captureByIR();
        void captureByCable();
};


//Fin del archivo configuration.h
// Path: src/configuration.cpp


