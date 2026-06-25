#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class SensorManager
{
private:

    float _co2;
    float _temperature;
    float _humidity;

    bool _connected;

    unsigned long _lastRead;

public:

    void begin();

    void update();

    float getCO2();

    float getTemperature();

    float getHumidity();

    bool isConnected();
};

extern SensorManager sensor;

#endif
