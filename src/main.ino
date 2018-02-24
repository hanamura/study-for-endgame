#include "Keyboard.h"

#define PIN_LED 17
#define PIN_A 3

bool aCurrState = LOW;
bool aLastState = LOW;

void setup() {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  aCurrState = digitalRead(PIN_A);

  if (aCurrState == aLastState) {
    return;
  }

  if (aCurrState == HIGH) {
    Serial.println("Push");
    digitalWrite(PIN_LED, LOW);
    Keyboard.press(0x61);
  } else {
    Serial.println("Release");
    digitalWrite(PIN_LED, HIGH);
    Keyboard.release(0x61);
  }

  aLastState = aCurrState;
}
