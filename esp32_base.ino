#include "config.h"
#include "display.h"
#include "sensor.h"
#include "wifi.h"
#include "web.h"
#include "log.h"
#include "screenManager.h"

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
