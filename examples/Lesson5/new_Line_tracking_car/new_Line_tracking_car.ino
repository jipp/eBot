#include "Arduino.h"
#include <EBot.h>

int speed = 115;

EBot eBot = EBot();

void setup() {
  eBot.begin();
  eBot.setSpeed(speed);
}

void loop() {
  int num1,num2,num3;
  num1 = eBot.getLine1();
  num2 = eBot.getLine2();
  num3 = eBot.getLine3();
  if ((num1 == 0) && num2 && num3) {
    eBot.setDirection(EBot::ROTATELEFT);
    delay(2);
    while(1) {
      num2 = eBot.getLine2();
      if (num2 == 1) {
        eBot.setDirection(EBot::ROTATELEFT);
        delay(2);
      } else {
        break;
      }
    }
  } else if (num1 && num2 && (num3 == 0)) {
    eBot.setDirection(EBot::ROTATERIGHT);
    delay(2);
    while(1) {
      num2 = eBot.getLine2();
      if (num2 == 1) {
        eBot.setDirection(EBot::ROTATERIGHT);
        delay(2);
      } else {
        break;
      }
    }
  }
  else {
    eBot.setDirection(EBot::FORWARD);
    delay(2);
  }
}
