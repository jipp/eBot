#include "Arduino.h"
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
  pinMode(LED_BUILTIN, OUTPUT);     //initialize LED as an output
  Serial.begin(9600);       // debug output at 9600 baud
  eBot.begin();
  eBot.stop();
}

void loop() {
  RED = eBot.decode();
  if(RED==A) {  
    Serial.println("A");
    eBot.forward();
  } else if(RED==B) {
    Serial.println("B");
    eBot.backward();
  } else if(RED==C) {
    Serial.println("C");
    eBot.rotateLeft();
  } else if(RED==D) {
    Serial.println("D");
    eBot.rotateRight();
  } else if(RED==X) { 
    Serial.println("X");
    eBot.stop();
  }
} 

