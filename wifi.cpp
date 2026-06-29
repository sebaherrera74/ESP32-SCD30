#include "Wifi.h"
#include "Config.h"
#include "Log.h"

#include <WiFi.h>

WifiManager wifi;

void WifiManager::begin()
{
    logger.info("Conectando WiFi...");

    WiFi.mode(WIFI_STA);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    unsigned long start = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");

        if (millis() - start > 10000)
        {
            logger.error("No se pudo conectar al WiFi");
            _connected = false;
            return;
        }
    }

    _connected = true;

    logger.info("WiFi conectado");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}



void WifiManager::update()
{
  _connected = (WiFi.status() == WL_CONNECTED);
}


bool WifiManager::isConnected()
{
    return _connected;
}

String WifiManager::getIP()
{
  if (!_connected)
        return "";

    return WiFi.localIP().toString();
    return "";
}
