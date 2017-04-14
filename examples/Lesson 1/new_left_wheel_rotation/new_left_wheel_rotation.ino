#include "Arduino.h"
#include <EBot.h>

int speed = 150;
EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.leftWheelForward();
  delay(500);
  eBot.leftWheelStop();
  delay(500);
  eBot.leftWheelBackward();
  delay(500);
  eBot.leftWheelStop();
  delay(500);
  eBot.leftWheelForward(speed);
  delay(500);
  eBot.leftWheelStop();
  delay(500);
  eBot.leftWheelBackward(speed);
  delay(500);
  eBot.leftWheelStop();
  delay(500);
}
