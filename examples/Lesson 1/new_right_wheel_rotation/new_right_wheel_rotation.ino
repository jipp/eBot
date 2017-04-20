#include "Arduino.h"
#include <EBot.h>

int speed = 150;

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.setSpeed();
  eBot.setDirection(EBot::RIGHTWHEELFORWARD);
  delay(500);
  eBot.setDirection(EBot::RIGHTWHEELSTOP);
  delay(500);
  eBot.setDirection(EBot::RIGHTWHEELBACKWARD);
  delay(500);
  eBot.setDirection(EBot::RIGHTWHEELSTOP);
  delay(500);
  eBot.setSpeed(speed);
  eBot.setDirection(EBot::RIGHTWHEELFORWARD);
  delay(500);
  eBot.setDirection(EBot::RIGHTWHEELSTOP);
  delay(500);
  eBot.setDirection(EBot::RIGHTWHEELBACKWARD);
  delay(500);
  eBot.setDirection(EBot::RIGHTWHEELSTOP);
  delay(500);
}
