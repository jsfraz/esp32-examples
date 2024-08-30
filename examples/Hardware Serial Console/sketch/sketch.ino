#define RXD2 16
#define TXD2 17

void setup() {
  // Setup Serial2 on GPIO pins
   Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

void loop() {
  // Check if there is data coming
  if (Serial2.available()) {
    // Read string until newline character
    String str = Serial2.readStringUntil('\n');
    Serial2.println("String: " + str);
  }
}
