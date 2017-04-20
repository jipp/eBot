#include "Arduino.h"
#include <EBot.h>

int speed = 150;

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.setSpeed();
  eBot.setDirection(EBot::LEFTWHEELFORWARD);
  delay(500);
  eBot.setDirection(EBot::LEFTWHEELSTOP);
  delay(500);
  eBot.setDirection(EBot::LEFTWHEELBACKWARD);
  delay(500);
  eBot.setDirection(EBot::LEFTWHEELSTOP);
  delay(500);
  eBot.setSpeed(speed);
  eBot.setDirection(EBot::LEFTWHEELFORWARD);
  delay(500);
  eBot.setDirection(EBot::LEFTWHEELSTOP);
  delay(500);
  eBot.setDirection(EBot::LEFTWHEELBACKWARD);
  delay(500);
  eBot.setDirection(EBot::LEFTWHEELSTOP);
  delay(500);
}
