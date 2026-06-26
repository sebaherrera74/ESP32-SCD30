#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
private:

    unsigned long _previous;

public:

    Timer();

    bool elapsed(unsigned long interval);

    void reset();
};

#endif
