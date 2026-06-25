#ifndef CONFIG_H
#define CONFIG_H

//==================================================
// Información del proyecto
//==================================================

#define NOMBRE_PROYECTO   "ESP32_BASE"
#define VERSION           "1.0"

//==================================================
// OLED
//==================================================

#define SCREEN_WIDTH      128
#define SCREEN_HEIGHT     64
#define OLED_RESET        -1
#define OLED_ADDRESS      0x3C

//==================================================
// I2C
//==================================================

#define PIN_SDA           21
#define PIN_SCL           22

//==================================================
// WiFi Access Point
//==================================================

#define AP_SSID           "ESP32_BASE"
#define AP_PASSWORD       "12345678"

//==================================================
// Tiempos
//==================================================

#define TIEMPO_SENSOR     2000
#define TIEMPO_DISPLAY    500

#endif
