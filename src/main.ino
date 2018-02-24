#define PIN_LED 17
#define PIN_SWITCH 3

void setup() {
  pinMode(PIN_SWITCH, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIN_SWITCH) == HIGH) {
    Serial.println("Push");
    digitalWrite(PIN_LED, LOW);
  } else {
    Serial.println("Release");
    digitalWrite(PIN_LED, HIGH);
  }
}
