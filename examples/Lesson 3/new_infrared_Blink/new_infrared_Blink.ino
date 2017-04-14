#include "Arduino.h"
#include <EBot.h>

#define L 16738455

volatile int state = LOW;  //define default input mode
unsigned long RED;

EBot eBot = EBot();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //initialize LED as an output
  Serial.begin(9600);       // debug output at 9600 baud
  eBot.begin();
}

void stateChange() {
  state = !state;          
  digitalWrite(LED_BUILTIN, state);
}

void loop() {
  RED = eBot.decode();
  if (RED != 0) {
    Serial.println(RED);
  }
  if (RED == L) {  
    Serial.println("state changed!");
    stateChange();
  }
}

