#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.move(true);
}

void loop() {
  eBot.turnRight();
  delay(500);
  eBot.stop();
  delay(500);
}
