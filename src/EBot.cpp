#include "Arduino.h"
#include <EBot.h>

#ifdef IRREMOTE
IRrecv irrecv(receiverpin);
decode_results results;
#endif

EBot::EBot() {
}

EBot::~EBot() {
}

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
  servo.write(90);
  this->setDirection();
  this->setSpeed();
  #ifdef IRREMOTE
  irrecv.enableIRIn();
  #endif
}

void EBot::setDirection(EBot::direction move) {
  this->move = move;

  switch(this->move) {
    case STOP:
    this->stop();
    break;
    case FORWARD:
    this->forward(this->speed);
    break;
    case BACKWARD:
    this->backward(this->speed);
    break;
    case TURNLEFT:
    this->turnLeft(this->speed);
    break;
    case TURNRIGHT:
    this->turnRight(this->speed);
    break;
    case ROTATELEFT:
    this->rotateLeft(this->speed);
    break;
    case ROTATERIGHT:
    this->rotateRight(this->speed);
    break;
    case LEFTWHEELSTOP:
    this->leftWheelStop();
    break;
    case RIGHTWHEELSTOP:
    this->rightWheelStop();
    break;
    case LEFTWHEELFORWARD:
    this->leftWheelForward(this->speed);
    break;
    case RIGHTWHEELFORWARD:
    this->rightWheelForward(this->speed);
    break;
    case LEFTWHEELBACKWARD:
    this->leftWheelBackward(this->speed);
    break;
    case RIGHTWHEELBACKWARD:
    this->rightWheelBackward(this->speed);
    break;
  }
}

EBot::direction EBot::getDirection() {
  return this->move;
}

void EBot::setSpeed(int speed) {
  this->speed = boundaries(speed, 0, 255);
  this->setDirection(this->move);
}

int EBot::getSpeed() {
  return this->speed;
}

void EBot::stop() {
  leftWheelStop();
  rightWheelStop();
}

void EBot::forward(int speed) {
  leftWheelForward(speed);
  rightWheelForward(speed);
}

void EBot::backward(int speed) {
  leftWheelBackward(speed);
  rightWheelBackward(speed);
}

void EBot::turnLeft(int speed) {
  leftWheelStop();
  rightWheelForward(speed);
}

void EBot::turnRight(int speed) {
  leftWheelForward(speed);
  rightWheelStop();
}

void EBot::rotateLeft(int speed) {
  leftWheelBackward(speed);
  rightWheelForward(speed);
}

void EBot::rotateRight(int speed) {
  leftWheelForward(speed);
  rightWheelBackward(speed);
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

void EBot::leftWheelForward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::rightWheelForward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void EBot::leftWheelBackward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::rightWheelBackward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void EBot::setAngle(int angle) {
  angle = boundaries(angle, 0, 179);

  this->servo.write(angle);
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

unsigned long EBot::getIR() {
  unsigned long value = 0;
  #ifdef IRREMOTE
  if (irrecv.decode(&results)) {
    value = results.value;
    irrecv.resume(); // Receive the next value
  }
  #endif
  return value;
}

bool EBot::readLS1() {
  return digitalRead(LS1);
}

bool EBot::readLS2() {
  return digitalRead(LS2);
}

bool EBot::readLS3() {
  return digitalRead(LS3);
}

int EBot::boundaries(int value, int min, int max) {
  value = value < min ? min : value;
  value = value > max ? max : value;

  return value;
}
