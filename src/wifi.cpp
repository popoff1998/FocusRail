#include "wifi.hpp"

Wifi::Wifi()
{
}

//Escaneamos todos los AP disponibles y los devolvemos en una lista
void Wifi::scanNetworks()
{
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i)
    {
        Serial.println(WiFi.SSID(i));
    }
}

//Devuelve la lista de AP escaneados
WiFiClass Wifi::getNetworks()
{
    scanNetworks();
    return WiFi;
}


