#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.init();
}

void loop() {
  eBot.leftWheelForward(true);
  delay(500);
  eBot.stop();
  delay(500);
  eBot.leftWheelBackward(true);
  delay(500);
  eBot.stop();
  delay(500);
}
