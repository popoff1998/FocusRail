//Control de la camara
#include "camera.hpp"
#include "MD_multiCameraIrControl.h"
#include "config.hpp"
#include "motor.hpp"
#include "log.hpp"
#include <Arduino.h>

extern Motor MyMotor;

//Función para inicializar la cámara
void Camera::initCamera(Config config, Log log)
{
	// Configuración de los pines de control de la cámara
	pinMode(CAMERA_IR_PIN, OUTPUT);
	//Copiamos los valores de configuración
	capProf = config.capProf;
	capFotos = config.capFotos;
	capTime = config.capTime;
	camType = config.camType;
	camInterface = config.camInterface;
	//Inicializamos la interfaz IR
	setCameraIR(camType);
}

// Función para capturar una foto
void Camera::capturePhoto()
{
    if (camInterface == IR)
    {
        captureByIR();
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
    irInterface->begin();
}

void Camera::setCapProf(int prof)
{
    capProf = prof;
}

void Camera::setCapFotos(int fotos)
{
    capFotos = fotos;
}

void Camera::setCapTime(int time)
{
    capTime = time;
}

int Camera::getCapProf()
{
    return capProf;
}

int Camera::getCapFotos()
{
    return capFotos;
}

int Camera::getCapTime()
{
    return capTime;
}

void Camera::setCanonTime(int time)
{
    Canon* canon = (Canon*)irInterface;
    canon->setCanonTime(time);
}