#include <ESP7266Wifi.h>

const char *ssid = "Nyeedz";
const char *password = "17091995";

int ledPinSala = 13;

WifiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);

  pinMode(ledPinSala, OUTPUT);
  pinMode(ledPinSala, LOW);

  // Conect to Wifi network
  Serial.println();
  Serial.println('Conectando...');
  Serial.println(ssid);

  Wifi.begin(ssid, password);
}