#include "Arduino.h"

#include <EBot.h>

#define L 16738455

EBot eBot = EBot();
bool state = LOW;  //define default input mode
unsigned long RED;

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  RED = eBot.decode();
  Serial.println(RED);
  delay(150);
  if(RED==L) {
    stateChange();
  }
}
