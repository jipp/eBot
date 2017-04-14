#ifndef EBot_h
#define EBot_h

#include "Arduino.h"
#include <Servo.h>
#include <IRremote.h>

class EBot {
public:
  EBot();
  ~EBot();

  void begin();
  void rightWheelForward();
  void rightWheelForward(int speed);
  void rightWheelBackward();
  void rightWheelBackward(int speed);
  void rightWheelStop();
  void leftWheelForward();
  void leftWheelForward(int speed);
  void leftWheelBackward();
  void leftWheelBackward(int speed);
  void leftWheelStop();

private:
  Servo servo;

};

#endif
