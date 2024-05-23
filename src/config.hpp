#pragma once
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

//Para la captura
#define CAPPROF 10
#define CAPFOTOS 10
#define CAPTIME 3

//Para Canon
#define CANON_TIME 15


//Variables globales
#ifndef CONFIG_H
#define CONFIG_H
// Para la conexión a la red
const String SSID = "ORDENA";
const String PASSWORD = "28duque28";
const String HOSTNAME = "focusrail";

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
         int logType; //Tipo de log
         int canon_time; //Tiempo de espera de la señal IR para canon
         // Variables para el ssid y password de la red
         String ssid;;
         String password;
         String hostname;
       private:
         Preferences preferences; // Objeto de preferencias
};
#endif
