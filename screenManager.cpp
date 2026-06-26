#include "ScreenManager.h"
#include "Sensor.h"

#include "Display.h"
#include "Config.h"

ScreenManager screen;

Screen _currentScreen;
void ScreenManager::begin()
{
    _currentScreen = SCREEN_CO2;

}

void ScreenManager::drawCurrentScreen()
{
    switch (_currentScreen)
    {
        case SCREEN_CO2:

            showCO2();

            break;

        case SCREEN_TEMP:

            showTemperature();

            break;

        case SCREEN_HUM:

            showHumidity();

            break;

        case SCREEN_STATUS:

            showStatus();

            break;
    }
}

void ScreenManager::showCO2()
{
    display.showValue("CO2",
                      sensor.getCO2(),
                      "ppm");
}
void ScreenManager::showTemperature()
{
    display.showValue("TEMP",
                      sensor.getTemperature(),
                      "C");
}

void ScreenManager::showHumidity()
{
    display.showValue("HUM",
                      sensor.getHumidity(),
                      "%");
}

void ScreenManager::showStatus()
{
    display.showMessage("BUENA");
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
    drawCurrentScreen();

    if (!_timer.elapsed(SCREEN_TIME ))
        return;

    switch (_currentScreen)
    {
        case SCREEN_CO2:
            _currentScreen = SCREEN_TEMP;
            break;

        case SCREEN_TEMP:
            _currentScreen = SCREEN_HUM;
            break;

        case SCREEN_HUM:
            _currentScreen = SCREEN_STATUS;
            break;

        case SCREEN_STATUS:
            _currentScreen = SCREEN_CO2;
            break;
    }
}
