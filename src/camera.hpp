#pragma once

#include "MD_multiCameraIrControl.h"
#include "config.hpp"
#include "log.hpp"

// Defines de los pines de control de la cámara
#define CAMERA_CABLE_PIN 16
#define CAMERA_IR_PIN 17

class Camera
{
    public:
        //Metodos de la clase Camera
        Camera() {};
        void initCamera(Config,Log);
        void setCamera(int);
		void setInterface(int);
        void capturePhoto();
        //void capturePhotos();
		void setCameraIR(int);
        void setCapProf(int);
        void setCapFotos(int);
        void setCapTime(int);
        void setCanonTime(int);
        int getCapProf();
        int getCapFotos();
        int getCapTime();
    private:
        cCamera* irInterface;
		void captureByIR();
        void captureByCable();
        // Variables de la clase Camera
        int camType;
        int camInterface;
        int capProf;
        int capFotos;
        int capTime;
};


//Fin del archivo configuration.h
// Path: src/configuration.cpp


