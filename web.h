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

    String buildTitle();

    String buildStatus();

    String buildSensors();

    String buildRelay();
    
   
public:

    void begin();

    void update();
    String buildPage();
   String buildSensorJson();
};

extern WebManager web;

#endif
