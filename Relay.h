#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class RelayManager
{
public:

    void begin();

    void on();

    void off();

    void toggle();

    bool isOn();

private:

    bool _state = false;
};

extern RelayManager relay;

#endif
