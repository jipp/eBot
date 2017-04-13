#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.init();
  eBot.move(true);
}

void loop() {
  eBot.leftWheelForward();
  delay(500);
  eBot.stop();
  delay(500);
  eBot.leftWheelBackward();
  delay(500);
  eBot.stop();
  delay(500);
}
