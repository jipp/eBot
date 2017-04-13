#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.init();
  eBot.move(true);
}

void loop() {
  eBot.rightWheelForward();
  delay(500);
  eBot.stop();
  delay(500);
  eBot.rightWheelBackward();
  delay(500);
  eBot.stop();
  delay(500);
}
