#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <Arduino.h>
#include "Timer.h"

class ScreenManager
{
  private:

    Timer _timer;
public:

    void begin();

    void splash();

    void mainScreen();

    void errorScreen(String texto);

    void update();
};

extern ScreenManager screen;

#endif
