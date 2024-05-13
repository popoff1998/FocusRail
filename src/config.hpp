//Incluimos multicamera.h
#include "MD_multiCameraIrControl.h"
#include "Preferences.h"

// Defines de los tipos de cámara
#define CANON 0
#define NIKON 1
#define OLYMPUS 2
#define PENTAX 3
#define SONY 4
#define MINOLTA 5

// Defines de las interfaces de la cámara
#define CABLE 0
#define IR 1

//Para el log
#define SERIAL_LOG 0
#define WEB_LOG 1


//Variables globales
#ifndef CONFIG_H
#define CONFIG_H
//Variable Camera
extern cCamera *camera;

#define DEBUG 1
//Variables de control del log

//Prototipos de las funciones de configuration.cpp
class Config
{
    public:
       void initConfiguration(); //Inicializa la configuración de la aplicación
       void readConfiguration(); //Lee los valores del interface de la aplicación
       void writeConfiguration(); //Escribe los valores del interface de la aplicación   
       //Variables de configuración
         int capProf; //Profundidad de campo
         int capFotos; //Número de fotos a capturar
         int capTime; //Tiempo de captura
         int camType; //Tipo de cámara
         int camInterface; //Interfaz de la cámara
         int logType = WEB_LOG;
       private:
         Preferences preferences; // Objeto de preferencias
};
#endif
