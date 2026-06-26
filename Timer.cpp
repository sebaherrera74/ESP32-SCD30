#include "Timer.h"

Timer::Timer()
{
    _previous = millis();
}

bool Timer::elapsed(unsigned long interval)
{
    if (millis() - _previous >= interval)
    {
        _previous = millis();
        return true;
    }

    return false;
}

void Timer::reset()
{
    _previous = millis();
}
