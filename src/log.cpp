#include "log.hpp"

//Inicializamos el log
void Log::initLog(Config config)
{
    //Inicializamos el tipo de log
    logType = config.logType;
}

//Funcion para imprimir una linea en el log
void Log::println(const char* line)
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

void Log::println(int var)
{
    if (logType == SERIAL_LOG)
    {
        Serial.println(var);
    }
    else if (logType == WEB_LOG)
    {
        WebSerial.println(var);
    }
}

//Funcion para imprimir una linea en el log
void Log::print(const char* line)
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

void Log::print(int var)
{
    if (logType == SERIAL_LOG)
    {
        Serial.print(var);
    }
    else if (logType == WEB_LOG)
    {
        WebSerial.print(var);
    }
}