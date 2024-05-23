#include "config.hpp"

//Inicializa la configuración de la aplicación
void Config::initConfiguration()
{
    Preferences preferences;
    //Inicializamos las preferencias
    preferences.begin("focusrail", false);
    //Leemos las preferencias
    readConfiguration();
}    

//Leemos las preferencias del ESP32
void Config::readConfiguration()
{
    //Leemos las preferencias
    capProf = preferences.getInt("capProf", CAPPROF);
    capFotos = preferences.getInt("capFotos", CAPFOTOS);
    capTime = preferences.getInt("capTime", CAPTIME);
    camType = preferences.getInt("camType", CANON);
    camInterface = preferences.getInt("camInterface", IR);
    logType = preferences.getInt("logType", WEB_LOG);
    canon_time = preferences.getInt("canon_time", CANON_TIME);
    ssid = preferences.getString("ssid", SSID);
    password = preferences.getString("password", PASSWORD);
    hostname = preferences.getString("hostname", HOSTNAME);
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
    preferences.putInt("logType", logType);
    preferences.putInt("canon_time", canon_time);
    preferences.putString("ssid", ssid);
    preferences.putString("password", password);
    preferences.putString("hostname", hostname);
}
