#ifndef EBot_h
#define EBot_h

#include "Arduino.h"
#include <Servo.h>

class EBot {
private:
  Servo servo;
  static int boundaries(int value, int min, int max);

public:
  EBot();
  ~EBot();

  void begin();
  void stop();
  void rightWheelStop();
  void leftWheelStop();
  void rightWheelForward(int speed = 255);
  void rightWheelBackward(int speed = 255);
  void leftWheelForward(int speed = 255);
  void leftWheelBackward(int speed = 255);
  void forward(int speed = 255);
  void backward(int speed = 255);
  void rotateRight(int speed = 255);
  void turnRight(int speed = 255);
  void rotateLeft(int speed = 255);
  void turnLeft(int speed = 255);
  void write(int angle = 90);
  unsigned long distance();
  bool readLS1();
  bool readLS2();
  bool readLS3();
};

#endif
