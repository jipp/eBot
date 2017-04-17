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
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::rightWheelForward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void EBot::rightWheelForward(int speed) {
  speed = boundaries(speed, 0, 255);
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void EBot::rightWheelBackward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void EBot::rightWheelBackward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void EBot::rightWheelStop() {
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void EBot::leftWheelForward() {
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::leftWheelForward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::leftWheelBackward() {
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::leftWheelBackward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::leftWheelStop() {
  digitalWrite(ENB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::forward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::forward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::backward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::backward(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::rotateRight() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::rotateRight(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::rotateLeft() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::rotateLeft(int speed) {
  speed = boundaries(speed, 0, 255);

  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::write(int angle) {
  angle = boundaries(angle, 0, 180);

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
