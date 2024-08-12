#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char WIFI_SSID[] = "YOUR_SSID";    // TODO change
const char WIFI_PASSWORD[] = "YOUR_PASSWORD";    // TODO change

const float LATITUDE = 47.1915308;   // TODO change
const float LONGITUDE = -52.839761;  // TODO change
const String URL = "https://api.sunrisesunset.io/json?lat=" + String(LATITUDE) + "&lng=" + String(LONGITUDE);

StaticJsonDocument<1024> doc;
const char* sunrise;
const char* sunset;

void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect");
    delay(1000);
  }

  HTTPClient http;
  http.begin(URL);
  int httpCode = http.GET();

  // Result will be negative on error
  if (httpCode > 0) {
    // Status OK
    if (httpCode == HTTP_CODE_OK) {
      // Deserialize JSON
      DeserializationError error = deserializeJson(doc, http.getString());
      // Check errors
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
      } else {
        sunrise = doc["results"]["sunrise"];
        sunset = doc["results"]["sunset"];
      }
      Serial.println(URL);
    } else {
      // Other status
      Serial.println("HTTP status " + httpCode);
    }
  } else {
    // Error status
    Serial.println("HTTP status " + httpCode);
  }

  http.end();
}

void loop() {
  Serial.println("Sunrise: " + String(sunrise) + " Sunset: " + String(sunset));
  delay(1000);
}
