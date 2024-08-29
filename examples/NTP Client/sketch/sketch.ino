#include <WiFi.h>
#include "time.h"

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const long  gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;
const char* ntp_server = "pool.ntp.org";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  configTime(gmtOffset_sec, daylightOffset_sec, ntp_server);
}

void loop() {
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  }
  delay(1000);
}
