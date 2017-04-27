#include "Arduino.h"
#include <EBot.h>

int speed = 150;

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.setSpeed();
  eBot.setDirection(EBot::FORWARD);
  delay(1000);
  eBot.setDirection(EBot::BACKWARD);
  delay(1000);
  eBot.setDirection();
  eBot.setDirection(EBot::RIGHTWHEELFORWARD);
  delay(1000);
  eBot.setDirection();
  eBot.setDirection(EBot::LEFTWHEELFORWARD);
  delay(1000);
  eBot.setSpeed(speed);
  eBot.setDirection(EBot::FORWARD);
  delay(1000);
  eBot.setDirection(EBot::BACKWARD);
  delay(1000);
  eBot.setDirection();
  eBot.setDirection(EBot::RIGHTWHEELFORWARD);
  delay(1000);
  eBot.setDirection();
  eBot.setDirection(EBot::LEFTWHEELFORWARD);
  delay(1000);
}
