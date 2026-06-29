#include "Web.h"
#include <WebServer.h>
#include "log.h"
#include "sensor.h"

WebServer server(80);
WebManager web;


void handleRoot()
{
    server.send(
        200,
        "text/html",
        web.buildPage());
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

String WebManager::buildPage()
{
    String html;

    html += "<html>";

    html += "<head>";
    html += "<title>SIEE ESP32 BASE</title>";
    html += "<meta http-equiv=\"refresh\" content=\"2\">";
    html += "</head>";
  
    html += "<body>";

    html += "<h1>SIEE ESP32 BASE</h1>";

    html += "<hr>";

    html += "<h2>CO2</h2>";
    html += "<p>";
    html += String(sensor.getCO2(),0);
    html += " ppm</p>";

    html += "<h2>Temperatura</h2>";
    html += "<p>";
    html += String(sensor.getTemperature(),1);
    html += " C</p>";

    html += "<h2>Humedad</h2>";
    html += "<p>";
    html += String(sensor.getHumidity(),1);
    html += " %</p>";

    html += "<hr>";

    html += "<p>SIEE Framework</p>";

    html += "</body>";

    html += "</html>";

    return html;
}
