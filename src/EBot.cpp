#include "EBot.h"

#define IN1	6
#define IN2	7
#define IN3	8
#define IN4	9
#define ENA	5
#define ENB	11
#define LS1 10
#define LS2 4
#define LS3 2

#define	ServoPin	3

#define Echo	A4
#define Trig	A5

void EBot::begin() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  servo.attach(ServoPin);
  this->setDirection();
  this->setSpeed();
  this->setAngle();
}

void EBot::setSpeed(int speed) {
  this->speed = EBot::boundaries(speed, 120, 255);
  this->setDirection(this->direction);
}

int EBot::getSpeed() {
  return this->speed;
}

void EBot::setDirection(EBot::move direction) {
  this->direction = direction;
  switch(this->direction) {
   case STOP:
   this->stop();
   break;
   case FORWARD:
   this->forward();
   break;
   case BACKWARD:
   this->backward();
   break;
   case TURNLEFT:
   this->turnLeft();
   break;
   case TURNRIGHT:
   this->turnRight();
   break;
   case ROTATELEFT:
   this->rotateLeft();
   break;
   case ROTATERIGHT:
   this->rotateRight();
   break;
   case LEFTWHEELSTOP:
   this->leftWheelStop();
   break;
   case RIGHTWHEELSTOP:
   this->rightWheelStop();
   break;
   case LEFTWHEELFORWARD:
   this->leftWheelForward();
   break;
   case RIGHTWHEELFORWARD:
   this->rightWheelForward();
   break;
   case LEFTWHEELBACKWARD:
   this->leftWheelBackward();
   break;
   case RIGHTWHEELBACKWARD:
   this->rightWheelBackward();
   break;
 }
}

EBot::move EBot::getDirection() {
  return this->direction;
}

unsigned long EBot::getDistance() {
  unsigned long duration;

  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trig, LOW);
  duration = pulseIn(Echo, HIGH);

  return duration / 29 / 2;
}

void EBot::setAngle(int angle) {
  this->angle = EBot::boundaries(angle, 0, 179);

  this->servo.write(this->angle);
}

int EBot::getAngle() {
  return this->angle;
}

bool EBot::getLine1() {
  return digitalRead(LS1);
}

bool EBot::getLine2() {
  return digitalRead(LS2);
}

bool EBot::getLine3() {
  return digitalRead(LS3);
}

int EBot::boundaries(int value, int min, int max) {
  value = value < min ? min : value;
  value = value > max ? max : value;

  return value;
}

void EBot::stop() {
  leftWheelStop();
  rightWheelStop();
}

void EBot::forward() {
  leftWheelForward();
  rightWheelForward();
}

void EBot::backward() {
  leftWheelBackward();
  rightWheelBackward();
}

void EBot::turnLeft() {
  leftWheelStop();
  rightWheelForward();
}

void EBot::turnRight() {
  leftWheelForward();
  rightWheelStop();
}

void EBot::rotateLeft() {
  leftWheelBackward();
  rightWheelForward();
}

void EBot::rotateRight() {
  leftWheelForward();
  rightWheelBackward();
}

void EBot::leftWheelStop() {
  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::rightWheelStop() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void EBot::leftWheelForward() {
  analogWrite(ENB, this->speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::rightWheelForward() {
  analogWrite(ENA, this->speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void EBot::leftWheelBackward() {
  analogWrite(ENB, this->speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::rightWheelBackward() {
  analogWrite(ENA, this->speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
