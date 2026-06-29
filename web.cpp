#include "Web.h"
#include <WebServer.h>
#include "log.h"
WebServer server(80);
WebManager web;


void handleRoot()
{
    server.send(
        200,
        "text/html",
        "<h1>SIEE ESP32 BASE</h1>");
}
void WebManager::begin()
{
  server.on("/", handleRoot);

  server.begin();

  logger.info("Servidor Web iniciado");
}

void WebManager::update()
{
  server.handleClient();
}
