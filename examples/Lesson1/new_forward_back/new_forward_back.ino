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
  delay(500);
  eBot.setDirection();
  delay(500);
  eBot.setDirection(EBot::BACKWARD);
  delay(500);
  eBot.setDirection();
  delay(500);
  eBot.setSpeed(speed);
  eBot.setDirection(EBot::FORWARD);
  delay(500);
  eBot.setDirection();
  delay(500);
  eBot.setDirection(EBot::BACKWARD);
  delay(500);
  eBot.setDirection();
  delay(500);
}
