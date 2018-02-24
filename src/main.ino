#include "Keyboard.h"

#define PIN_LED 17
#define PIN_SWITCH 3

void setup() {
  pinMode(PIN_SWITCH, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(PIN_SWITCH) == HIGH) {
    Serial.println("Push");
    digitalWrite(PIN_LED, LOW);
    Keyboard.press(0x61);
  } else {
    Serial.println("Release");
    digitalWrite(PIN_LED, HIGH);
    Keyboard.release(0x61);
  }
}
