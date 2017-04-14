#include "Arduino.h"
#include <EBot.h>

int speed = 150;

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.rightWheelForward();
  delay(500);
  eBot.rightWheelStop();
  delay(500);
  eBot.rightWheelBackward();
  delay(500);
  eBot.rightWheelStop();
  delay(500);
  eBot.rightWheelForward(speed);
  delay(500);
  eBot.rightWheelStop();
  delay(500);
  eBot.rightWheelBackward(speed);
  delay(500);
  eBot.rightWheelStop();
  delay(500);
}
