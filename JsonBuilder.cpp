#include "JsonBuilder.h"

JsonBuilder::JsonBuilder()
{
    clear();
}

void JsonBuilder::clear()
{
    json = "{";

    first = true;
}

void JsonBuilder::add(String key, int value)
{
    if (!first)
    {
        json += ",";
    }

    json += "\"";
    json += key;
    json += "\":";
    json += String(value);

    first = false;
}


void JsonBuilder::add(String key, float value)
{
    if (!first)
    {
        json += ",";
    }

    json += "\"";
    json += key;
    json += "\":";
    json += String(value,1);

    first = false;
}

void JsonBuilder::add(String key, String value)
{
    if (!first)
    {
        json += ",";
    }

    json += "\"";
    json += key;
    json += "\":";

    json += "\"";
    json += value;
    json += "\"";

    first = false;
}

String JsonBuilder::build()
{
    return json + "}";
}
