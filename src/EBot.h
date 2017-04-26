#ifndef EBOT_H
#define EBOT_H

#include "Arduino.h"
#include <Servo.h>

class EBot {
public:
  enum move {
    STOP,
    FORWARD,
    BACKWARD,
    TURNLEFT,
    TURNRIGHT,
    ROTATELEFT,
    ROTATERIGHT,
    LEFTWHEELSTOP,
    RIGHTWHEELSTOP,
    LEFTWHEELFORWARD,
    RIGHTWHEELFORWARD,
    LEFTWHEELBACKWARD,
    RIGHTWHEELBACKWARD
  };

  void begin();
  void setSpeed(int speed=160);
  int getSpeed();
  void setDirection(move direction=STOP);
  move getDirection();
  unsigned long getDistance();
  void setAngle(int angle=90);
  int getAngle();

private:
  int speed;
  int angle;
  move direction;
  static int boundaries(int value, int min, int max);
  Servo servo;

  void stop();
  void forward();
  void backward();
  void turnLeft();
  void turnRight();
  void rotateLeft();
  void rotateRight();
  void leftWheelStop();
  void rightWheelStop();
  void leftWheelForward();
  void rightWheelForward();
  void leftWheelBackward();
  void rightWheelBackward();
};

#endif
