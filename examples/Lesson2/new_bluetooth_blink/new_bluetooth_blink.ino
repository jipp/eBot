#include "Arduino.h"
#include <EBot.h>

volatile int state = LOW;
char getstr;

EBot eBot = EBot();

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  eBot.begin();
}

void loop() {
  getstr = Serial.read();
  if (getstr == 'A') {
    stateChange();
  }
}
