#include "Sensor.h"
#include "Log.h"

SensorManager sensor;

void SensorManager::begin()
{
    logger.info("Iniciando SCD30");

    if (!_scd30.begin())
    {
        logger.error("SCD30 NO encontrado");

        _connected = false;
        return;
    }

    logger.info("SCD30 encontrado");

    _connected = true;

    _scd30.setMeasurementInterval(2);

    _co2 = 0;
    _temperature = 0;
    _humidity = 0;
}




void SensorManager::update()
{
    if (!_connected)
    {
        logger.error("Sensor desconectado");
        return;
    }

    if (!_timer.elapsed(500))
        return;

    logger.info("Consultando SCD30");

    if (!_scd30.dataReady())
    {
        logger.info("Esperando medicion...");
        return;
    }

    logger.info("Datos disponibles");

    if (!_scd30.read())
    {
        logger.error("Error leyendo SCD30");
        return;
    }

    logger.info("Lectura correcta");

    _co2 = _scd30.CO2;
    _temperature = _scd30.temperature;
    _humidity = _scd30.relative_humidity;

    logger.info("CO2 = " + String(_co2));
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
