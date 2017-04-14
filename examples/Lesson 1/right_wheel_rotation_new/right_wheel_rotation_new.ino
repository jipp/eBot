#include "Arduino.h"
#include <EBot.h>

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  eBot.rightWheelForward();
  delay(500);
  eBot.rightWheelStop();
  delay(500);
  eBot.rightWheelBackward();
  delay(500);
  eBot.rightWheelStop();
  delay(500);
  eBot.rightWheelForward(150);
  delay(500);
  eBot.rightWheelStop();
  delay(500);
  eBot.rightWheelBackward(150);
  delay(500);
  eBot.rightWheelStop();
  delay(500);
}
