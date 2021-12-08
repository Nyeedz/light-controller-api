#include <ESP8266WiFi.h>

const char *ssid = "Nyeedz";
const char *password = "17091995";

int ledPinBar = 14;
int ledPinSala = 15;
int httpCode = http.GET();
String header;

WifiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);

  // Conect to Wifi network
  Serial.println();
  Serial.println('Conectando...');
  Serial.println(ssid);

  Wifi.begin(ssid, password);
  Serial.println(WiFi.localIP());

  server.on('/toggleLight', toggleLight);
  server.on('/discover', discover);
}

void loop()
{
  server.handleClient();
}

void toggleLight()
{
  String id = server.argName('id');
  int pinStatus = digitalRead(id);

  if (pinStatus == LOW)
  {
    pinMode(id, HIGH);
  }
  else
  {
    pinMode(id, LOW);
  }
  server.send(200);
}

void discover()
{
  int pinStatus = digitalRead(id);

  if (pinStatus) {
    server.send(200);
  } else {
    server,send(404);
  }
}