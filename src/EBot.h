#ifndef EBot_h
#define EBot_h

#include "Arduino.h"

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
  void forward();
  void forward(int speed); 
  void backward();
  void backward(int speed); 

private:

};

#endif
