#ifndef WEB_H
#define WEB_H

#include <Arduino.h>

class WebManager
{
  private:

   String buildStyle();

    String buildHeader();

    String buildBody();

    String buildFooter();
public:

    void begin();

    void update();
    String buildPage();

};

extern WebManager web;

#endif
