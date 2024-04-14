//Control de la captura de fotos
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
    // Configuración de los pines de control de la cámara
    pinMode(CAPTURE_CABLE_PIN, OUTPUT);
    pinMode(CAPTURE_IR_PIN, OUTPUT); 
    //Por defecto la cámara es Canon y la interfaz es por cable
    camType = CANON;
    camInterface = CABLE;
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
void capturePhoto()
{
}


