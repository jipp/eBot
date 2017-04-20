#include "Arduino.h"
#include <EBot.h>

int speed = 150;
unsigned long distanceWarning = 40;
unsigned long rightDistance = 0,leftDistance = 0,middleDistance = 0 ;

EBot eBot = EBot();

void setup() {
  eBot.begin();
  eBot.setSpeed(speed);
  eBot.setDirection();
}

void loop() {
  eBot.setAngle(90);
  delay(500);
  middleDistance = eBot.getDistance();

  if (middleDistance <= distanceWarning) {
    eBot.setDirection();
    delay(500);
    eBot.setAngle(5);
    delay(1000);
    rightDistance = eBot.getDistance();

    delay(500);
    eBot.setAngle(90);
    delay(1000);
    eBot.setAngle(180);
    delay(1000);
    leftDistance = eBot.getDistance();

    delay(500);
    eBot.setAngle(90);
    delay(1000);
    if (rightDistance > leftDistance) {
      eBot.setDirection(EBot::ROTATERIGHT);
      delay(300);
    } else if (rightDistance < leftDistance) {
      eBot.setDirection(EBot::ROTATELEFT);
      delay(300);
    } else if ((rightDistance <= 20) || (leftDistance <= 20)) {
      eBot.setDirection(EBot::BACKWARD);
      delay(150);
    } else {
      eBot.setDirection(EBot::FORWARD);
    }
  } else {
    eBot.setDirection(EBot::FORWARD);
  }
}
