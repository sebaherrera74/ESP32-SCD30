#include "Log.h"

Logger logger;

void Logger::begin()
{
    Serial.begin(115200);
    delay(500);

    Serial.println();
}

void Logger::info(String texto)
{
    Serial.print("[INFO ] ");
    Serial.println(texto);
}

void Logger::warn(String texto)
{
    Serial.print("[WARN ] ");
    Serial.println(texto);
}

void Logger::error(String texto)
{
    Serial.print("[ERROR] ");
    Serial.println(texto);
}
