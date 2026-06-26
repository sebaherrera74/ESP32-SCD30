#include "ScreenManager.h"
#include "Sensor.h"

#include "Display.h"

ScreenManager screen;

void ScreenManager::begin()
{

}

void ScreenManager::splash()
{
    display.showMessage("SIEE");
}

void ScreenManager::mainScreen()
{
  
    display.showValue("CO2",
                      sensor.getCO2(),
                      "ppm");
    
}

void ScreenManager::errorScreen(String texto)
{
    display.showMessage(texto);
}

  void ScreenManager::update()
  {
    if (!_timer.elapsed(250))
        return;

    mainScreen();
}
