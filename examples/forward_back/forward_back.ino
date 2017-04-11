#include "Arduino.h"

#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.move(true);
}

void loop() {
  eBot.forward();
  delay(500);
  eBot.stop();
  delay(500);
  eBot.backward();
  delay(500);
  eBot.stop();
  delay(500);
}
