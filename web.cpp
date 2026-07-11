  #include "Web.h"
  #include <WebServer.h>
  #include "log.h"
  #include "sensor.h"
  #include "Relay.h"
  
  WebServer server(80);
  WebManager web;

 
void handleRoot()
  {
      server.send(
          200,
          "text/html",
          web.buildPage());
  }
void handleOn()
  {
      relay.on();
  
      server.send(
          200,
          "text/html",
          web.buildPage());
  }
  
void handleOff()
  {
      relay.off();
  
      server.send(
          200,
          "text/html",
          web.buildPage());
  }

void handleSensor()
{
    web.sendSensorJson();
}

void handleInfo()
{
    web.sendInfoJson();
}
void WebManager::sendSensorJson()
{
    server.send(
        200,
        "application/json",
        buildSensorJson());
}

void WebManager::sendInfoJson()
{
    server.send(
        200,
        "application/json",
        buildInfoJson());
}
  
  void WebManager::begin()
  {
    server.on("/", handleRoot);
  
    server.on("/on", handleOn);
  
    server.on("/off", handleOff);
  
    server.begin();
    server.on("/sensor", handleSensor);
    server.on("/info", handleInfo);
  
    logger.info("Servidor Web iniciado");
  }


  void WebManager::update()
  {
    server.handleClient();
  }
  
  
  
  String WebManager::buildPage()
  {
      String html;
  
      html += buildHeader();
  
      html += buildBody();
  
      html += buildFooter();
  
      return html;
  }
  
  String WebManager::buildBody()
  {
      String html;
  
      html += buildTitle();
  
     html += buildSensors();
     html += buildRelay();
      
      return html;
  }
  
  
  String WebManager::buildFooter()
  {
      String html;
  
      html += "</div>";
  
      html += "</body>";
  
      html += "</html>";
  
      return html;
  }
  
  String WebManager::buildStyle()
  {
      String html;
  
      html += "<style>";
  
      html += "body{";
      html += "font-family:Arial;";
      html += "background:#ECEFF1;";
      html += "text-align:center;";
      html += "margin:30px;";
      html += "}";
  
      html += ".card{";
      html += "background:white;";
      html += "padding:25px;";
      html += "border-radius:15px;";
      html += "box-shadow:0px 4px 15px rgba(0,0,0,0.3);";
      html += "display:inline-block;";
      html += "min-width:320px;";
      html += "}";
  
      html += "button{";
      html += "width:180px;";
      html += "height:45px;";
      html += "font-size:18px;";
      html += "border:none;";
      html += "border-radius:8px;";
      html += "margin:10px;";
      html += "cursor:pointer;";
      html += "}";
  
      html += "</style>";
  
      return html;
  }
  
  String WebManager::buildHeader()
  {
      String html;
  
      html += "<html>";
  
      html += "<head>";
  
      html += "<meta charset='UTF-8'>";
  
      html += "<title>SIEE ESP32 BASE</title>";
  
      html += "<meta http-equiv='refresh' content='2'>";
  
      html += buildStyle();
  
      html += "</head>";
  
      html += "<body>";
  
      html += "<div class='card'>";
  
      return html;
  }
  
  String WebManager::buildTitle()
  {
      String html;
  
      html += "<h1>SIEE ESP32 BASE</h1>";
  
      html += "<hr>";
  
      return html;
  }
  
  String WebManager::buildSensors()
  {
      String html;
  
      html += "<h2>CO₂</h2>";
      html += "<p>";
      html += String(sensor.getCO2(), 0);
      html += " ppm</p>";
  
      html += "<h2>Temperatura</h2>";
      html += "<p>";
      html += String(sensor.getTemperature(), 1);
      html += " °C</p>";
  
      html += "<h2>Humedad</h2>";
      html += "<p>";
      html += String(sensor.getHumidity(), 1);
      html += " %</p>";
  
      html += "<hr>";
  
      return html;
  }
  String WebManager::buildRelay()
  {
      String html;
  
      html += "<p>SIEE Framework</p>";
  
      html += "<br><br>";
  
      html += "<a href='/on'>";
      html += "<button>ENCENDER</button>";
      html += "</a>";
  
      html += "<br><br>";
  
      html += "<a href='/off'>";
      html += "<button>APAGAR</button>";
      html += "</a>";
  
      html += "<h2>Relé</h2>";
  
      if (relay.isOn())
      {
          html += "<p>🟢 ENCENDIDO</p>";
      }
      else
      {
          html += "<p>🔴 APAGADO</p>";
      }
  
      return html;
  }

  String WebManager::buildSensorJson()
{
    String json;

    json += "{";

    json += "\"co2\":";
    json += String(sensor.getCO2(), 0);

    json += ",";

    json += "\"temperature\":";
    json += String(sensor.getTemperature(), 1);

    json += ",";

    json += "\"humidity\":";
    json += String(sensor.getHumidity(), 1);

    json += "}";

    return json;
}
String WebManager::buildInfoJson()
{
    String json;

    json += "{";

    json += "\"name\":\"ESP32_BASE\",";
    json += "\"version\":\"0.1.0\",";
    json += "\"author\":\"Sebastian Herrera\",";
    json += "\"framework\":\"SIEE Framework\"";

    json += "}";

    return json;
}
