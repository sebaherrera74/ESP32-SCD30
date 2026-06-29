#ifndef WEB_H
#define WEB_H

#include <Arduino.h>

class WebManager
{
public:

    void begin();

    void update();
    String buildPage();

};

extern WebManager web;

#endif
