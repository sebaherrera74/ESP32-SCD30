#include "Config.h"
#include "Display.h"
#include "Sensor.h"
#include "Wifi.h"
#include "Web.h"
#include "Log.h"
#include "ScreenManager.h"
#include "Timer.h"

Timer timer;

void setup()
{
    logger.begin();

    display.begin();

    screen.begin();
    sensor.begin();
    screen.splash();

    logger.info("Sistema iniciado");
}

void loop(){
   if (timer.elapsed(1000))
    {
        logger.info("Pasó un segundo");
    }
}
    
  
