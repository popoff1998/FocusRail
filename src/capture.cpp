//Control de la captura de fotos
#include "MD_multiCameraIrControl.h"
#include "camera.h"
#include "capture.h"
#include "movement.h"
#include "configuration.h"
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
void capturePhotos(camera)
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
        capturePhoto(camera);
    }
}

// Función para capturar una foto
void capturePhoto(Camera camera)
{
    // Dependiendo de la interfaz de la cámara disparamos de una forma u otra
    if (Camera.camInterface == CABLE)
    {
        camera.captureByCable();
    }
    else if (camInterface == IR)
    {
        camera.captureByIR();
    }
}



// Fucnion para disparar la cámara por infrarrojos
void captureByIR()
{
    // Hacemos un shutterNow de camera
    camera.shutterNow();
}
