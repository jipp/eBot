#ifdef IRREMOTE
#include <IRremote.h>
#endif

#ifndef EBot_h
#define EBot_h

#include "Arduino.h"
#include <Servo.h>

#define IN1	6
#define IN2	7
#define IN3	8
#define IN4	9
#define ENA	5
#define ENB	11

#define	ServoPin	3

#define Echo	A4
#define Trig	A5

#define receiverpin	12

#define LS1 10
#define LS2 4
#define LS3 2

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
  unsigned long result();
};

#endif
