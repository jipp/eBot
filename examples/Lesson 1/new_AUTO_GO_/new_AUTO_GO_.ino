#include "Arduino.h"
#include <EBot.h>

int speed = 150;

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.forward();
  delay(1000);
  eBot.backward();
  delay(1000);
  eBot.rightWheelForward();
  delay(1000);
  eBot.leftWheelForward();
  delay(1000);
  eBot.forward(speed);
  delay(1000);
  eBot.backward(speed);
  delay(1000);
  eBot.rightWheelForward(speed);
  delay(1000);
  eBot.leftWheelForward(speed);
  delay(1000);
}
