#include "Arduino.h"
#include <EBot.h>

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
}

void EBot::stop() {
  leftWheelStop();
  rightWheelStop();
}

void EBot::rightWheelStop() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void EBot::leftWheelStop() {
  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::rightWheelForward(int speed) {
  speed = boundaries(speed, 0, 255);
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void EBot::rightWheelBackward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void EBot::leftWheelForward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::leftWheelBackward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::forward(int speed) {
  leftWheelForward(speed);
  rightWheelForward(speed);
}

void EBot::backward(int speed) {
  leftWheelBackward(speed);
  rightWheelBackward(speed);
}

void EBot::rotateRight(int speed) {
  leftWheelForward(speed);
  rightWheelBackward(speed);
}

void EBot::turnRight(int speed) {
  leftWheelForward(speed);
  rightWheelStop();
}

void EBot::rotateLeft(int speed) {
  leftWheelBackward(speed);
  rightWheelForward(speed);
}

void EBot::turnLeft(int speed) {
  leftWheelStop();
  rightWheelForward(speed);
}

void EBot::write(int angle) {
  angle = boundaries(angle, 0, 179);

  servo.write(angle);
}

unsigned long EBot::distance() {
  unsigned long duration;

  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trig, LOW);
  duration = pulseIn(Echo, HIGH);

  return duration / 29 / 2;
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
