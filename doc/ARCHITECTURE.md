# ESP32 BASE
# Architecture

Autor: Sebastián Herrera

---

# Objetivo

ESP32 BASE es un framework modular desarrollado sobre ESP32 cuyo objetivo es facilitar el desarrollo de aplicaciones IoT, instrumentación electrónica y automatización.

La filosofía del proyecto consiste en construir módulos independientes, reutilizables y de baja dependencia entre sí.

Cada módulo debe tener una única responsabilidad.

---

# Filosofía del Framework

En lugar de escribir todo el código dentro del archivo principal (.ino), el proyecto está dividido en módulos especializados.

Cada módulo encapsula su funcionamiento y expone únicamente la interfaz necesaria.

Ejemplo:

SensorManager
    ↓
Display

SensorManager
    ↓
WebManager

El resto del sistema no necesita conocer cómo funciona internamente cada módulo.

---

# Evolución del proyecto

## Etapa 1

### Configuración inicial

Se creó la estructura base del proyecto.

Archivos principales

Config
Log
Timer
Display
SensorManager
ScreenManager

Objetivo:

Crear una base limpia y modular.

---

## Etapa 2

### Logger

Se desarrolló Logger para unificar todos los mensajes enviados por el puerto serie.

Ejemplo

logger.info()

logger.warning()

logger.error()

Beneficios

- Código más limpio
- Depuración sencilla
- Posibilidad futura de guardar logs en memoria o enviarlos por red

---

## Etapa 3

### Timer

Se implementó una clase Timer para eliminar el uso de delay().

Se comenzó a trabajar utilizando millis().

Ejemplo

timer.elapsed(1000)

Esto permitió que todo el sistema sea completamente no bloqueante.

---

## Etapa 4

### Display

Se desarrolló Display.cpp y Display.h.

Toda la lógica del OLED quedó encapsulada.

El resto del programa nunca utiliza directamente display.print().

Siempre utiliza funciones propias del módulo.

Ejemplo

display.showValue()

---

## Etapa 5

### ScreenManager

Se creó ScreenManager para controlar las distintas pantallas del OLED.

Pantallas implementadas

BOOT

CO2

Temperatura

Humedad

Status

Se implementó una máquina de estados.

Ejemplo

BOOT

↓

CO2

↓

TEMP

↓

HUM

↓

STATUS

↓

CO2

---

Conceptos aprendidos

Máquinas de estado

Responsabilidad única

Separación entre lógica y presentación

---

## Etapa 6

### SensorManager

Se encapsuló completamente el sensor SCD30.

El resto del programa obtiene los datos mediante

sensor.getCO2()

sensor.getTemperature()

sensor.getHumidity()

Nunca accede directamente al hardware.

---

## Etapa 7

### WiFiManager

Se desarrolló un módulo dedicado exclusivamente a la conexión WiFi.

Funciones

begin()

update()

isConnected()

getIP()

Conceptos aprendidos

Modo estación (STA)

Conexión mediante Router

Obtención de IP

---

## Etapa 8

### WebManager

Se implementó un servidor Web embebido utilizando WebServer.

El ESP32 ahora responde a peticiones HTTP.

Ejemplo

GET /

↓

handleRoot()

↓

buildPage()

↓

HTML

↓

Navegador

---

Se implementó la construcción dinámica del HTML.

Funciones

buildPage()

buildHeader()

buildBody()

buildFooter()

Posteriormente

buildStyle()

El CSS quedó separado del contenido.

---

Conceptos aprendidos

HTTP

Servidor Web

Cliente

HTML

CSS

Separación entre presentación y lógica

---

## Etapa 9

### RelayManager

Se desarrolló el primer módulo de control.

Funciones

begin()

on()

off()

toggle()

isOn()

El WebManager nunca controla directamente un GPIO.

Siempre utiliza

relay.on()

relay.off()

Conceptos aprendidos

Encapsulamiento

Abstracción

Control remoto

---

## Etapa 10

### Control desde navegador

Se agregaron nuevas rutas

/

on

/off

El navegador ahora puede controlar hardware.

Flujo

Usuario

↓

Botón

↓

GET /on

↓

handleOn()

↓

RelayManager

↓

GPIO

↓

LED

---

# Arquitectura actual

setup()

↓

Logger.begin()

↓

Display.begin()

↓

Sensor.begin()

↓

Wifi.begin()

↓

Web.begin()

↓

Relay.begin()

↓

Screen.begin()

---

loop()

↓

Sensor.update()

↓

Wifi.update()

↓

Web.update()

↓

Screen.update()

---

# Relación entre módulos

                 SensorManager
                      │
          ┌───────────┴───────────┐
          │                       │
          ▼                       ▼
      Display                WebManager

                 RelayManager
                      ▲
                      │
                WebManager

---

# Principios utilizados

✓ Modularidad

✓ Encapsulamiento

✓ Responsabilidad única

✓ Bajo acoplamiento

✓ Alta reutilización

✓ Programación no bloqueante

✓ Máquinas de estado

✓ Arquitectura por capas

---

# Objetivo a corto plazo

- Mejorar CSS

- Dashboard Web

- Botones dinámicos

- JSON

- AJAX

- API REST

---

# Objetivo a mediano plazo

- LittleFS

- OTA

- MQTT

- ESP-NOW

- Almacenamiento de configuración

- Dashboard profesional

---

# Objetivo final

Construir un Framework IoT reutilizable para:

• Instrumentación electrónica

• Automatización

• Data Logger

• Domótica

• Laboratorio

• Investigación

• Sistemas embebidos

• PLC de pequeña escala

• Interfaces HMI

• Monitoreo remoto

• Control distribuido

---


# Actualización - Etapa Web y Control Remoto

## Refactorización del WebManager

El WebManager fue dividido en pequeñas funciones con una única responsabilidad.

Antes:

buildPage()

↓

HTML completo

Ahora:

buildPage()

↓

buildHeader()

↓

buildStyle()

↓

buildBody()

↓

buildFooter()

### Beneficios

- Código más legible.
- Fácil mantenimiento.
- Permite modificar el CSS sin tocar el contenido.
- Facilita agregar nuevas secciones al Dashboard.

---

## Arquitectura del servidor Web

Cliente (Navegador)

↓

HTTP GET

↓

WebServer

↓

handleRoot()

↓

WebManager::buildPage()

↓

HTML

↓

Cliente


## Estado del desarrollo

### ESP-NOW

Se implementó la estructura inicial del módulo `ESPNow`:

- Inicialización del protocolo.
- Registro de Peer.
- Protocolo compartido (`Protocol.h`).
- Proyecto independiente `ESP32_SLAVE`.

Las pruebas de comunicación entre dos ESP32 quedan temporalmente suspendidas hasta verificar el entorno de hardware (cables USB y configuración de ambas placas).

El desarrollo continúa sobre `ESP32_BASE`, priorizando mejoras en la interfaz web y la arquitectura del framework.


# Reflexión

El proyecto comenzó como un simple ejemplo para leer un sensor SCD30.

Actualmente evolucionó hacia un framework modular para ESP32 basado en buenas prácticas de ingeniería de software.

Cada nueva funcionalidad se incorpora como un módulo independiente, manteniendo el código organizado, reutilizable y escalable.

La filosofía del proyecto es aprender los conceptos antes que memorizar el código, construyendo una base sólida para futuros desarrollos.