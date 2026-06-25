#include "config.h"
#include "display.h"
#include "sensor.h"
#include "wifi.h"
#include "web.h"
#include "log.h"

void setup()
{
    logger.begin();

    logger.info("ESP32 BASE");

    display.begin();

    display.splash();

    logger.info("Sistema iniciado");
}

void loop()
{

}
