#include "Arduino.h"
#define WOKE
#include <EBot.h>

#define A 16736925
#define B 16754775
#define X 16712445
#define C 16720605
#define D 16761405

int ABS=150;
unsigned long RED;

EBot eBot = EBot();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  eBot.begin();
  eBot.setSpeed(speed);
  eBot.setDirection();
}

void loop() {
  RED = eBot.getIR();
  if(RED==A) {
    Serial.println("A");
    eBot.setDirection(EBot::FORWARD);
  } else if(RED==B) {
    Serial.println("B");
    eBot.setDirection(EBot::BACKWARD);
  } else if(RED==C) {
    Serial.println("C");
    eBot.setDirection(EBot::ROTATELEFT);
  } else if(RED==D) {
    Serial.println("D");
    eBot.setDirection(EBot::ROTATERIGHT);
  } else if(RED==X) {
    Serial.println("X");
    eBot.setDirection();
  }
}
