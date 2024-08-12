#include <WiFi.h>

const char WIFI_SSID[] = "YOUR_SSID";    // TODO change
const char WIFI_PASSWORD[] = "YOUR_PASSWORD";    // TODO change

void setup() {
  Serial.begin(9600); 

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect");
    delay(1000);
  }
}

void loop() {
  Serial.println("Connected");
  delay(1000);
}
