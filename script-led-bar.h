#include <ESP7266Wifi.h>

const char *ssid = "Nyeedz";
const char *password = "17091995";

int ledPinBar = 14;

WifiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);

  pinMode(ledPinBar, OUTPUT);
  pinMode(ledPinBar, LOW);

  // Conect to Wifi network
  Serial.println();
  Serial.println('Conectando...');
  Serial.println(ssid);

  Wifi.begin(ssid, password);
}