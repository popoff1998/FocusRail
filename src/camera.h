#include "MD_multiCameraIrControl.h"

// Defines de los pines de control de la cámara
#define CAMERA_CABLE_PIN 32
#define CAMERA_IR_PIN 33
#define CAPTURE_CABLE_PIN 34

// Variables globales
#ifndef CAMERA_H
#define CAMERA_H
#endif

class Camera
{
    public:
        Camera();
        void initCamera();
        void setCamera(int);
		void setInterface(int);
		void captureByIR();
		void setCameraIR(int);
		void captureByCable();
        int camType;
        int camInterface;
        cCamera* irInterface;
    private:
};

//Fin del archivo configuration.h
// Path: src/configuration.cpp


