#include "config.hpp"
// Para webserial
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

class Log 
{
public:
    void initLog(Config);
    void println(char *);
    void print(char *);
private:
    int logType;    
};

