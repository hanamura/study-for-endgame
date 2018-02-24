#include "Keyboard.h"

const int numRows = 2;
const int numCols = 2;

const int rowPins[numRows] = {3, 4};
const int colPins[numCols] = {5, 6};
const byte codes[numRows][numCols] = {
  {0x61, 0x62},
  {0x63, 0x64}
};

bool currState[numRows][numCols];
bool lastState[numRows][numCols];

int i, j;

void setup() {
  for (i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
  }

  for (i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT);
  }

  for (i = 0; i < numRows; i++) {
    for (j = 0; j < numCols; j++) {
      currState[i][j] = LOW;
      lastState[i][j] = LOW;
    }
    digitalWrite(rowPins[i], LOW);
  }

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (i = 0; i < numRows; i++) {
    digitalWrite(rowPins[i], HIGH);

    for (j = 0; j < numCols; j++) {
      currState[i][j] = digitalRead(colPins[j]);

      if (currState[i][j] != lastState[i][j]) {
        Serial.print("Key: (");
        Serial.print(i);
        Serial.print(",");
        Serial.print(j);
        Serial.print(")");

        if (currState[i][j] == HIGH) {
          Serial.println(" Down");
          Keyboard.press(codes[i][j]);
        } else {
          Serial.println(" Up");
          Keyboard.release(codes[i][j]);
        }
      }

      lastState[i][j] = currState[i][j];
    }

    digitalWrite(rowPins[i], LOW);
  }
}
