

#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

class WifiManager
{
public:

    void begin();

    void update();

    bool isConnected();

    String getIP();

private:

    bool _connected = false;
};

extern WifiManager wifi;

#endif
