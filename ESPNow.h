#ifndef ESPNOW_H
#define ESPNOW_H

#include <Arduino.h>

class ESPNowManager
{
public:

    void begin();

    void update();

    bool sendRelayOn();

    bool sendRelayOff();

};

extern ESPNowManager espNow;

#endif
