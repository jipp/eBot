#include "Arduino.h"
#include <EBot.h>

int speed = 150;
unsigned long distanceWarning = 40;
unsigned long rightDistance = 0,leftDistance = 0,middleDistance = 0 ;

EBot eBot = EBot();

void setup() {
  eBot.begin();
  eBot.stop();
}

void loop() {
  eBot.write(90);
  delay(500);
  middleDistance = eBot.distance();

  if (middleDistance <= distanceWarning) {
    eBot.stop();
    delay(500);
    eBot.write(5);
    delay(1000);
    rightDistance = eBot.distance();

    delay(500);
    eBot.write(90);
    delay(1000);
    eBot.write(180);
    delay(1000);
    leftDistance = eBot.distance();

    delay(500);
    eBot.write(90);
    delay(1000);
    if (rightDistance > leftDistance) {
      eBot.rotateRight(speed);
      delay(300);
    } else if (rightDistance < leftDistance) {
      eBot.rotateLeft(speed);
      delay(300);
    } else if ((rightDistance <= 20) || (leftDistance <= 20)) {
      eBot.backward(speed);
      delay(150);
    } else {
      eBot.forward(speed);
    }
  } else {
    eBot.forward(speed);
  }
}
