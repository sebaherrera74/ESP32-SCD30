#include "ScreenManager.h"
#include "Sensor.h"
#include "Config.h"

#include "Display.h"
#include "Config.h"

ScreenManager screen;

Screen _currentScreen;
void ScreenManager::begin()
{
  changeScreen(SCREEN_BOOT);

}

void ScreenManager::drawCurrentScreen()
{
    switch (_currentScreen)
    {
        case SCREEN_BOOT:
        showBoot();
        break;     
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

    // Tiempo del BOOT
    if (_currentScreen == SCREEN_BOOT)
    {
        if (!_timer.elapsed(5000))
            return;
    }
    else
    {
        if (!_timer.elapsed(SCREEN_TIME))
            return;
    }

    switch (_currentScreen)
    {
        case SCREEN_BOOT:
            changeScreen(SCREEN_CO2);
            break;

        case SCREEN_CO2:
              changeScreen(SCREEN_TEMP);
            break;

        case SCREEN_TEMP:
            changeScreen(SCREEN_HUM);
            break;

        case SCREEN_HUM:
             changeScreen(SCREEN_STATUS);
            break;

        case SCREEN_STATUS:
            changeScreen(SCREEN_CO2);
            break;
    }
}

void ScreenManager::showBoot()
{
    display.showBoot(
        FW_NAME,
        FW_VERSION);
}

void ScreenManager::changeScreen(Screen next)
{
    _currentScreen = next;

    _timer.reset();
}
