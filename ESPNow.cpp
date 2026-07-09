#include "ESPNow.h"
#include <esp_now.h>
#include <WiFi.h>
#include "Protocolo.h"
#include "Log.h"

ESPNowManager espNow;

//Direccion MAC del otro esp32

uint8_t peerAddress[] =
{
    0x24,
    0x62,
    0xAB,
    0xFF,
    0x49,
    0xA4
};

void ESPNowManager::begin()
{
  logger.info("Inicializando ESP-NOW");

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK)
    {
        logger.error("Error inicializando ESP-NOW");
        return;
    }

esp_now_peer_info_t peerInfo = {};

memcpy(peerInfo.peer_addr, peerAddress, 6);

peerInfo.channel = 0;

peerInfo.encrypt = false;

if (esp_now_add_peer(&peerInfo) != ESP_OK)
{
    logger.error("No se pudo agregar Peer");
    return;
}

logger.info("Peer agregado correctamente");

bool ok = sendRelayOn();

if (ok)
{
    logger.info("Mensaje enviado");
}
else
{
    logger.error("Error enviando mensaje");
}

logger.info("ESP-NOW inicializado");

}

void ESPNowManager::update()
{

}

bool ESPNowManager::sendRelayOn()
{
    Command cmd;

    cmd.device = DEVICE_RELAY;
    cmd.action = CMD_ON;
    cmd.value = 1;

    esp_err_t result =
        esp_now_send(
            peerAddress,
            (uint8_t *)&cmd,
            sizeof(cmd));

    return (result == ESP_OK);
}
 
bool ESPNowManager::sendRelayOff()
{
    return false;
}
