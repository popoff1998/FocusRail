//Control de la camara
#include "camera.h"
#include "MD_multiCameraIrControl.h"
#include "configuration.h"
#include <Arduino.h>

//Función para inicializar la cámara
Camera initCamera()
{
    // Configuración de los pines de control de la cámara
    pinMode(CAMERA_CABLE_PIN, OUTPUT);
    pinMode(CAMERA_IR_PIN, OUTPUT);
    // Por defecto la cámara es Canon y la interfaz es por cable
    Camera cam;
    cam.setCamera(CANON);
    cam.setInterface(CABLE);
	return cam;
}

//Funcion setCamera
void Camera::setCamera(int camType)
{
    //Si el interfaz es por cable
    if (camInterface == CABLE)
    {
    }
}

// Funcion para disparar la cámara por cable
void Camera::captureByCable()
{
    // Disparamos la cámara
    digitalWrite(CAPTURE_CABLE_PIN, HIGH);
    delay(100);
    digitalWrite(CAPTURE_CABLE_PIN, LOW);
}

// Funcion para disparar la cámara por infrarrojos
void Camera::captureByIR()
{
	// Disparamos la cámara
	irInterface->shutterNow();
}

void Camera::setCameraIR(int camType)
{
    //Si ya estaba definida la cámara la eliminamos
    if (irInterface != NULL)
    {
        delete camera;
    }
    //Definimos la cámara
    switch (camType)
    {
        case CANON:
            camera = new Canon(CAMERA_IR_PIN);
            break;
        case NIKON:
            camera = new Nikon(CAMERA_IR_PIN);
            break;
        case OLYMPUS:
            camera = new Olympus(CAMERA_IR_PIN);
            break;
        case PENTAX:
            camera = new Pentax(CAMERA_IR_PIN);
            break;
        case SONY:
            camera = new Sony(CAMERA_IR_PIN);
            break;
        case MINOLTA:
            camera = new Minolta(CAMERA_IR_PIN);
            break;
    }
}
