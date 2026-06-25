#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
class Display
{
public:

    void begin();

    void splash();

    void clear();

    void showMessage(String texto);

    void showValue(String titulo,
                   float valor,
                   String unidad);

    void update();
};

extern Display display;   // <-- ESTA LÍNEA FALTA
#endif
