#include "Arduino.h"
#include <EBot.h>

volatile int state = LOW;//The initial state of the function is defined as a low level
char getstr;    //Defines a function that receives the Bluetooth character

EBot eBot = EBot();

void stateChange() {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //initialize LED as an output
  Serial.begin(9600);       // debug output at 9600 baud
  eBot.begin();
}

void loop() {
  getstr = Serial.read();//The Bluetooth serial port to receive the data in the function
  if (getstr == 'A') {
    stateChange();
  }
}
