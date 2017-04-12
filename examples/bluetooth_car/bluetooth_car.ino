#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

bool state = LOW;
char getstr;
int ABS=150;

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  eBot.move(ABS);
  eBot.stop();
}

void loop() {
  getstr=Serial.read();
  if (getstr=='f') {
    eBot.forward();
  } else if (getstr=='b') {
    eBot.backward();
    delay(200);
  } else if (getstr=='l') {
    eBot.turnLeft();
    delay(200);
  } else if (getstr=='r') {
    eBot.turnRight();
    delay(200);
  } else if (getstr=='s') {
    eBot.stop();
  } else if (getstr=='A') {
    stateChange();
  }
}
