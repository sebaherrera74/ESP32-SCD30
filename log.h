#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

class Logger
{
  public:

    void begin();

    void info(String texto);

    void warn(String texto);

    void error(String texto);
};

extern Logger logger;

#endif
