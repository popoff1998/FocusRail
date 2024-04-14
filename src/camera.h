// Defines de los pines de control de la cámara
#define CAMERA_CABLE_PIN 32
#define CAMERA_IR_PIN 33

// Variables globales
#ifndef CAMERA_H
#define CAMERA_H
// Variable Camera
//extern cCamera *camera;
#endif

class Camera
{
    public:
        Camera();
        void initCamera();
        void setCamera(int);
    private:
        cCamera *irInterface;
        int camType;
        int camInterface;
};

//Fin del archivo configuration.h
// Path: src/configuration.cpp


