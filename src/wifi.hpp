#include <WiFi.h>
#include "config.hpp"

class Wifi
{
    public:
        Wifi();
        void scanNetworks();
        WiFiClass getNetworks();
    private:
        char ssid[32];
        char password[32];
};