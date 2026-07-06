#include "Config.h"
#include "Display.h"
#include "Sensor.h"
#include "Wifi.h"
#include "Web.h"
#include "Log.h"
#include "ScreenManager.h"
#include "Timer.h"
#include "Web.h"
#include "Relay.h"

Timer timer;

void setup()
{
    logger.begin();

    display.begin();

    screen.begin();
    sensor.begin();
    screen.splash();
    wifi.begin();
    web.begin();
    relay.begin();
    logger.info("Sistema iniciado");
}

void loop()
{
    sensor.update();

    screen.update();
    wifi.update();
    web.update();
}

    
  
