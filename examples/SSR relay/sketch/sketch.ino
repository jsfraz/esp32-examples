const int RELAY = 13;

void setup() {
    pinMode(RELAY, OUTPUT);
}

void loop() {
  digitalWrite(RELAY, HIGH);
  delay(10000);
  digitalWrite(RELAY, LOW);
  delay(10000);
}
