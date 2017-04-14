#include "Arduino.h"
#include <EBot.h>

int speed = 150;
EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.rightWheelForward();
  eBot.leftWheelForward();
  delay(500);
  eBot.rightWheelStop();
  eBot.leftWheelStop();
  delay(500);
  eBot.rightWheelBackward();
  eBot.leftWheelBackward();
  delay(500);
  eBot.rightWheelStop();
  eBot.leftWheelStop();
  delay(500);
  eBot.rightWheelForward(speed);
  eBot.leftWheelForward(speed);
  delay(500);
  eBot.rightWheelStop();
  eBot.leftWheelStop();
  delay(500);
  eBot.rightWheelBackward(speed);
  eBot.leftWheelBackward(speed);
  delay(500);
  eBot.rightWheelStop();
  eBot.leftWheelStop();
  delay(500);
}
