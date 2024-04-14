//Control de la captura de fotos
#include "MD_multiCameraIrControl.h"
#include "camera.h"
#include "capture.h"
#include <Arduino.h>

//Definimos las variables globales
int capProf;
int capFotos;
int capTime;

int camType;
int camInterface;

void initCapture()
{
    //Ponemos los valores por defecto de la captura
    capProf = 10;
    capFotos = 10;
    capTime = 1;   
}

// Funcion para iniciar la captura de fotos
void capturePhotos()
{
    //Calculamos la distancia de movimiento en funcion de captFotos y capProf
    float distance = (float)capProf / (float)capFotos;

    // Iniciamos la captura de fotos
    for (int i = 0; i < capFotos; i++)
    {
        // Movemos el motor
        moveMotorDistance(distance, FORWARD);
        // Esperamos el tiempo de captura
        delay(capTime * 1000);
        // Capturamos la foto
        capturePhoto();
    }
}

// Función para capturar una foto
void capturePhoto(int camInterface)
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

// Funcion para disparar la cámara por cable
void captureByCable()
{
    // Disparamos la cámara
    digitalWrite(CAPTURE_CABLE_PIN, HIGH);
    delay(100);
    digitalWrite(CAPTURE_CABLE_PIN, LOW);
}

// Fucnion para disparar la cámara por infrarrojos
void captureByIR()
{
    // Hacemos un shutterNow de camera
    camera.shutterNow();
}
