void setup() {
  Serial.begin(9600);
}

void loop() {
  // Check if there is data comming
  if (Serial.available()) {
    // Read string until newline character
    String str = Serial.readStringUntil('\n');
    Serial.println("String: " + str);
  }
}