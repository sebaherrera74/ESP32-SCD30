#ifndef JSON_BUILDER_H
#define JSON_BUILDER_H

#include <Arduino.h>

class JsonBuilder
{
public:

    JsonBuilder();

    void clear();

    void add(String key, String value);

    void add(String key, int value);

    void add(String key, float value);

    String build();

private:

    String json;

    bool first;
};

#endif
