#include "Config.h"
#include "Display.h"
#include "Sensor.h"
#include "Wifi.h"
#include "Web.h"
#include "Log.h"
#include "ScreenManager.h"

void setup()
{
    logger.begin();

    display.begin();

    screen.begin();

    screen.splash();

    logger.info("Sistema iniciado");
}

void loop(){
  
}
