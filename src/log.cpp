#include "log.hpp"

//Inicializamos el log
void Log::initLog(Config config)
{
    //Inicializamos el tipo de log
    logType = config.logType;
}

//Funcion para imprimir una linea en el log
void Log::println(std::string line)
{
    if(logType == SERIAL_LOG)
    {
        Serial.println(line);
    }
    else if(logType == WEB_LOG)
    {
        WebSerial.println(line);
    }
}

//Funcion para imprimir una linea en el log
void Log::print(std::string line)
{
    if(logType == SERIAL_LOG)
    {
        Serial.print(line);
    }
    else if(logType == WEB_LOG)
    {
        WebSerial.print(line);
    }
}
