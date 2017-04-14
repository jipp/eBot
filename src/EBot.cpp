#include "Arduino.h"
#include <EBot.h>

#define Echo  A4
#define Trig  A5
#define ServoPin  3
#define LightSensor1  10
#define LightSensor2  4
#define LightSensor3  2
#define receiverpin 12

int IN1 = 6;
int IN2 = 7;
int IN3 = 8;
int IN4 = 9;
int ENA = 5;
int ENB = 11;
IRrecv irrecv(receiverpin);

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
  irrecv.enableIRIn();
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
