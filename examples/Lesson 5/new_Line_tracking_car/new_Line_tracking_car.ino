#include "Arduino.h"
#include <EBot.h>

int speed = 115;

EBot eBot = EBot();

void setup() {
  eBot.begin();
}

void loop() {
  int num1,num2,num3;
  num1 = readLS1();
  num2 = readLS2();
  num3 = readLS3();
  if ((num1 == 0) && num2 && num3) {
    eBot.rotateLeft();          //The sensor detected that right car turn left immediately when it meets black line
    delay(2);
    while(1) {
      num2 = readLS2();         //Cycle to judge degree of intermediate sensor,
      if (num2 == 1) {
        eBot.rotateLeft();                     //If num2==1 does not go to the middle position, continue to turn left.
        delay(2);
      } else {
        break;                      //Detection of num2==0 instructions turned over, out of the loop, detection of three sensors’ statusand then make appropriate action
      }
    }                                       //The following and so on
  } else if (num1 && num2 && (num3 == 0)) {
    eBot.rotateRight();
    delay(2);
    while(1) {
      num2 = readLS2();
      if (num2 == 1) {
        eBot.rotateRight();
        delay(2);
      } else {
        break;
      }
    }
  }
  else {
    eBot.forward();
    delay(2);
  }
}
