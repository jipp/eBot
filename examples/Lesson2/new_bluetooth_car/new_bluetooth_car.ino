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
  eBot.setDirection();
}

void loop() {
  getstr=Serial.read();
  switch (getstr) {
    case 'f':
    eBot.setSpeed();
    eBot.setDirection(EBot::FORWARD);
    break;
    case 'b':
    eBot.setSpeed();
    eBot.setDirection(EBot::BACKWARD);
    break;
    case 'l':
    eBot.setSpeed(150);
    eBot.setDirection(EBot::ROTATELEFT);
    break;
    case 'r':
    eBot.setSpeed(150);
    eBot.setDirection(EBot::ROTATERIGHT);
    break;
    case 's':
    eBot.setDirection();
    break;
    case 'A':
    stateChange();
    break;
  }
}
