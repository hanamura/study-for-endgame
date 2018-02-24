#include "Keyboard.h"

const int numKeys = 3;

const int pins[numKeys] = {3, 4, 5};
const byte codes[numKeys] = {0x61, 0x62, 0x63};

bool currState[numKeys];
bool lastState[numKeys];

int i;

void setup() {
  for (i = 0; i < numKeys; i++) {
    pinMode(pins[i], INPUT);
    currState[i] = LOW;
    lastState[i] = LOW;
  }

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (i = 0; i < numKeys; i++) {
    currState[i] = digitalRead(pins[i]);

    if (currState[i] != lastState[i]) {
      Serial.print("Key: ");
      Serial.print(i);
      if (currState[i] == HIGH) {
        Serial.println(" Down");
        Keyboard.press(codes[i]);
      } else {
        Serial.println(" Up");
        Keyboard.release(codes[i]);
      }
    }

    lastState[i] = currState[i];
  }
}
