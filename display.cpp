#include "display.h"
#include "config.h"
#include "log.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET);

Display display;

void Display::begin()
{
    Wire.begin(PIN_SDA, PIN_SCL);

    if(!oled.begin(SSD1306_SWITCHCAPVCC,OLED_ADDRESS))
    {
        logger.error("OLED no encontrado");

        while(true);
    }

    logger.info("OLED iniciado");
}

void Display::clear()
{
    oled.clearDisplay();
}

void Display::showMessage(String texto)
{
    oled.clearDisplay();

    oled.setTextColor(WHITE);

    oled.setTextSize(2);

    oled.setCursor(0,25);

    oled.println(texto);

    oled.display();
}

void Display::splash()
{
    showMessage("SIEE");

    delay(1500);
}

void Display::update()
{

}
