#include "Keyboard.h"

#define PIN_LED 17
#define PIN_A 3
#define PIN_B 4
#define KC_A 0x61
#define KC_B 0x62

bool aCurrState = LOW;
bool aLastState = LOW;
bool bCurrState = LOW;
bool bLastState = LOW;

void setup() {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  aCurrState = digitalRead(PIN_A);

  if (aCurrState != aLastState) {
    if (aCurrState == HIGH) {
      Serial.println("A Down");
      digitalWrite(PIN_LED, LOW);
      Keyboard.press(KC_A);
    } else {
      Serial.println("A Up");
      digitalWrite(PIN_LED, HIGH);
      Keyboard.release(KC_A);
    }
    aLastState = aCurrState;
  }

  bCurrState = digitalRead(PIN_B);

  if (bCurrState != bLastState) {
    if (bCurrState == HIGH) {
      Serial.println("B Down");
      Keyboard.press(KC_B);
    } else {
      Serial.println("B Up");
      Keyboard.release(KC_B);
    }
    bLastState = bCurrState;
  }
}
