#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.init();
  eBot.move(true);
}

void loop() {
  eBot.forward();
  delay(1000);
  eBot.backward();
  delay(1000);
  eBot.turnLeft();
  delay(1000);
  eBot.turnRight();
  delay(1000);
}
