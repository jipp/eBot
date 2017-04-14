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
  void stop();
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
  void forward();
  void forward(int speed);
  void backward();
  void backward(int speed);
  void rotateRight();
  void rotateRight(int speed);
  void rotateLeft();
  void rotateLeft(int speed);
  void write(int angle);
  unsigned long distance();
  unsigned long decode();

private:
  Servo servo;
};

#endif
