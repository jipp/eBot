#include "Arduino.h"
#define WOKE
#include <EBot.h>

#define L 16738455

volatile int state = LOW;
unsigned long RED;

EBot eBot = EBot();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  eBot.begin();
}

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void loop() {
  RED = eBot.getIR();
  if (RED != 0) {
    Serial.println(RED);
  }
  if (RED == L) {
    Serial.println("state changed!");
    stateChange();
  }
}
