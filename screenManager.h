#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <Arduino.h>
#include "Timer.h"


enum Screen
{
    SCREEN_CO2,
    SCREEN_TEMP,
    SCREEN_HUM,
    SCREEN_STATUS
};



class ScreenManager
{
  private:

    Timer _timer;

    void drawCurrentScreen();

    void showCO2();

    void showTemperature();

    void showHumidity();

    void showStatus();
public:

    void begin();

    void splash();

    void mainScreen();

    void errorScreen(String texto);

    void update();
};

extern ScreenManager screen;

#endif
