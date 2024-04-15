//Control de la camara
#include "camera.h"
#include "MD_multiCameraIrControl.h"
#include "configuration.h"
#include "motor.h"
#include <Arduino.h>

extern Motor MyMotor;

//Función para inicializar la cámara
void Camera::initCamera()
{
    // Configuración de los pines de control de la cámara
    pinMode(CAMERA_CABLE_PIN, OUTPUT);
    pinMode(CAMERA_IR_PIN, OUTPUT);
    // Por defecto la cámara es Canon y la interfaz es por cable
    setCamera(CANON);
    setInterface(CABLE);
}

// Función para capturar una foto
void Camera::capturePhoto()
{
    // Dependiendo de la interfaz de la cámara disparamos de una forma u otra
    if (camInterface == CABLE)
    {
        captureByCable();
    }
    else if (camInterface == IR)
    {
        captureByIR();
    }
}
// Funcion para iniciar la captura de fotos
void Camera::capturePhotos()
{
    // Calculamos la distancia de movimiento en funcion de captFotos y capProf
    float distance = (float)capProf / (float)capFotos;

    // Iniciamos la captura de fotos
    for (int i = 0; i < capFotos; i++)
    {
        // Movemos el motor
        MyMotor.moveMotorDistance(distance, FORWARD);
        // Esperamos el tiempo de captura
        delay(capTime * 1000);
        // Capturamos la foto
        capturePhoto();
    }
}

//Funcion setCamera
void Camera::setCamera(int type)
{
    camType = type;
    setCameraIR(camType);
}
//Funcion setInterface
void Camera::setInterface(int interface)
{
    camInterface = interface;
}   

// Funcion para disparar la cámara por cable
void Camera::captureByCable()
{
    // Disparamos la cámara
    digitalWrite(CAPTURE_CABLE_PIN, HIGH);
    delay(100);
    digitalWrite(CAPTURE_CABLE_PIN, LOW);
}

// Fucnion para disparar la cámara por infrarrojos
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
        delete irInterface;
    }
    //Definimos la cámara
    switch (camType)
    {
        case CANON:
            irInterface = new Canon(CAMERA_IR_PIN);
            break;
        case NIKON:
            irInterface = new Nikon(CAMERA_IR_PIN);
            break;
        case OLYMPUS:
            irInterface = new Olympus(CAMERA_IR_PIN);
            break;
        case PENTAX:
            irInterface = new Pentax(CAMERA_IR_PIN);
            break;
        case SONY:
            irInterface = new Sony(CAMERA_IR_PIN);
            break;
        case MINOLTA:
            irInterface = new Minolta(CAMERA_IR_PIN);
            break;
    }
}
