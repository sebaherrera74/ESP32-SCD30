#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <Arduino.h>
class ScreenManager
{
public:

    void begin();

    void splash();

    void mainScreen();

    void errorScreen(String texto);

    void update();
};

extern ScreenManager screen;

#endif
