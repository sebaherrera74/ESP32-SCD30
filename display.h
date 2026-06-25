#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

class Display
{
private:

public:

    void begin();

    void splash();

    void clear();

    void showMessage(String texto);

    void update();
};

extern Display display;

#endif
