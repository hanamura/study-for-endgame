#include "Keyboard.h"

#define PIN_LED 17

const int numKeys = 2;

const int pins[numKeys] = {3, 4};
const byte codes[numKeys] = {0x61, 0x62};

bool currState[numKeys];
bool lastState[numKeys];

int i;

void setup() {
  pinMode(PIN_LED, OUTPUT);

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
        if (i == 0) {
          digitalWrite(PIN_LED, LOW);
        }
      } else {
        Serial.println(" Up");
        Keyboard.release(codes[i]);
        if (i == 0) {
          digitalWrite(PIN_LED, HIGH);
        }
      }
    }

    lastState[i] = currState[i];
  }
}
