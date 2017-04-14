#include "Arduino.h"
#include <EBot.h>

volatile int state = LOW;//The initial state of the function is defined as a low level
char getstr;    //Defines a function that receives the Bluetooth character
int speed = 150;

EBot eBot = EBot();

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //initialize LED as an output
  Serial.begin(9600);       // debug output at 9600 baud
  eBot.begin();
  eBot.stop();
}

void loop() {
  getstr=Serial.read();
  if (getstr=='f') {
    eBot.forward();
  } else if(getstr=='b') {
    eBot.back();
    delay(200);
  } else if(getstr=='l') {
    eBot.rotateLeft();
    delay(200);
  } else if(getstr=='r') {
    eBot.rotateRight();
    delay(200);
  } else if(getstr=='s') {
    eBot.stop();     
  } else if(getstr=='A') {
    stateChange();
  }
}
