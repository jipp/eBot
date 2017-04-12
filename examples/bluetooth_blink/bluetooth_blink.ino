#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

bool state = LOW;
char getstr;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void loop() {
  getstr=Serial.read();//The Bluetooth serial port to receive the data in the function
  if(getstr=='A'){
    stateChange();
  }
}
