#ifndef EBot_h
#define EBot_h

#include "Arduino.h"
#include <Servo.h>
#include <IRremote.h>

#define ENA 5
#define ENB 11
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define Echo  A4
#define Trig  A5
#define ServoPin  3
#define LightSensor1  10
#define LightSensor2  4
#define LightSensor3  2
#define receiverpin 12

class EBot {
public:
  EBot();
  ~EBot();

  enum line { OK, RIGHT, LEFT, NOK};

  void init();
  void move(bool speed);
  void move(int speed);
  void stop();
  void leftWheelForward();
  void leftWheelBackward();
  void rightWheelForward();
  void rightWheelBackward();
  void forward();
  void backward();
  void turnLeft();
  void turnRight();
  void barkLeft();
  void barkRight();
  float distance();
  void servoRotate(int angle);
  line followLine();
  unsigned long decode();

private:
  Servo servo;
  IRrecv irrecv(receiverpin);

};

#endif
