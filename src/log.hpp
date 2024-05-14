#pragma once
#include <string>
#include <Arduino.h>
#include "config.hpp"
// Para webserial
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

class Log 
{
public:
    void initLog(Config);
    void println(const char*);
    void print(const char*);
    void println(int);
    void print(int);
private:
    int logType;
};

