#include "Arduino.h"
#include <EBot.h>

int IN1 = 6;
int IN2 = 7;
int IN3 = 8;
int IN4 = 9;
int ENA = 5;
int ENB = 11;

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
}

void EBot::rightWheelForward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void EBot::rightWheelForward(int speed) {
  analogWrite(ENA, speed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void EBot::rightWheelBackward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void EBot::rightWheelBackward(int speed) {
  analogWrite(ENA, speed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void EBot::rightWheelStop() {
  digitalWrite(ENA,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

void EBot::leftWheelForward() {
  digitalWrite(ENB,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void EBot::leftWheelForward(int speed) {
  analogWrite(ENB, speed);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void EBot::leftWheelBackward() {
  digitalWrite(ENB,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void EBot::leftWheelBackward(int speed) {
  analogWrite(ENB, speed);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void EBot::leftWheelStop() {
  digitalWrite(ENB,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void EBot::forward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void EBot::forward(int speed) {
  analogWrite(ENA, speed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENB, speed);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void EBot::backward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void EBot::backward(int speed) {
  analogWrite(ENA, speed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENB, speed);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
