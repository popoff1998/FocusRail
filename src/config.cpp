#include "config.hpp"

//Inicializa la configuración de la aplicación
void Config::initConfiguration()
{
    //Inicializamos variables
    logType = WEB_LOG;
    Preferences preferences;
    //Inicializamos las preferencias
    preferences.begin("focusrail", false);
}    

//Leemos las preferencias del ESP32
void Config::readConfiguration()
{
    //Leemos las preferencias
    capProf = preferences.getInt("capProf", 10);
    capFotos = preferences.getInt("capFotos", 10);
    capTime = preferences.getInt("capTime", 10);
    camType = preferences.getInt("camType", CANON);
    camInterface = preferences.getInt("camInterface", IR);
}

//Escribimos las preferencias del ESP32
void Config::writeConfiguration()
{
    //Escribimos las preferencias
    preferences.putInt("capProf", capProf);
    preferences.putInt("capFotos", capFotos);
    preferences.putInt("capTime", capTime);
    preferences.putInt("camType", camType);
    preferences.putInt("camInterface", camInterface);
}
