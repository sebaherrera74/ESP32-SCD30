#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <Arduino.h>

enum Device
{
    DEVICE_RELAY = 1
};

enum CommandType
{
    CMD_OFF = 0,
    CMD_ON = 1
};

struct Command
{
    uint8_t device;
    uint8_t action;
    uint8_t value;
};

#endif
