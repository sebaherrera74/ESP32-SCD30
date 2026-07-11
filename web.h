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
    String buildSensorJson();
    String buildInfoJson();
    
   
public:

    void begin();

    void update();
    String buildPage();
    //String buildSensorJson();
    void sendSensorJson();
    
    void sendInfoJson();
};

extern WebManager web;

#endif
