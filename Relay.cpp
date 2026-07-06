#include "Relay.h"
#include "Config.h"

RelayManager relay;

void RelayManager::begin()
{
    pinMode(RELAY_PIN, OUTPUT);

    off();
}

void RelayManager::on()
{
    digitalWrite(RELAY_PIN, HIGH);

    _state = true;
}

void RelayManager::off()
{
    digitalWrite(RELAY_PIN, LOW);

    _state = false;
}

void RelayManager::toggle()
{
    if (_state)
        off();
    else
        on();
}

bool RelayManager::isOn()
{
    return _state;
}
