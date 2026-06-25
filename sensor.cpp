#include "Sensor.h"

SensorManager sensor;

void SensorManager::begin()
{
    _co2 = 400;

    _temperature = 25;

    _humidity = 50;

    _connected = true;

    _lastRead = millis();
}

void SensorManager::update()
{
    if (millis() - _lastRead < 1000)
        return;

    _lastRead = millis();

    _co2 += 15;

    if (_co2 > 1500)
        _co2 = 400;

    _temperature += 0.2;

    if (_temperature > 30)
        _temperature = 25;

    _humidity += 1;

    if (_humidity > 70)
        _humidity = 50;
}

float SensorManager::getCO2()
{
    return _co2;
}

float SensorManager::getTemperature()
{
    return _temperature;
}

float SensorManager::getHumidity()
{
    return _humidity;
}

bool SensorManager::isConnected()
{
    return _connected;
}
