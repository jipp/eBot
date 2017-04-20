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
  eBot.stop();
}

void loop() {
  getstr=Serial.read();
  switch (getstr) {
    case 'f':
    eBot.forward();
    break;
    case 'b':
    eBot.backward();
    break;
    case 'l':
    eBot.rotateLeft(150);
    break;
    case 'r':
    eBot.rotateRight(150);
    break;
    case 's':
    eBot.stop();
    break;
    case 'A':
    stateChange();
    break;
  }
}
