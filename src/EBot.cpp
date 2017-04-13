#include "Arduino.h"
#include <EBot.h>

EBot::EBot() {
}

EBot::~EBot() {
  servo.detach();
}

void EBot::init() {
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

EBot::~EBot() {
  servo.detach();
}

void EBot::move(bool speed) {
  digitalWrite(ENA, speed);
  digitalWrite(ENB, speed);
}

void EBot::move(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void EBot::stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::leftWheelForward() {
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void EBot::leftWheelBackward() {
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void EBot::rightWheelForward() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void EBot::rightWheelBackward() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void EBot::forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::barkLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void EBot::barkRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

float EBot::distance() {
  float distance = 0.0;

  digitalWrite(Trig, LOW);
  delayMicroseconds(20);
  digitalWrite(Trig, HIGH);
  distance = pulseIn(Echo, HIGH);

  return distance/58;
}

void EBot::servoRotate(int angle) {
  angle = angle < 0 ? 0 : angle;
  angle = angle > 180 ? 180 : angle;

  servo.write(angle);
}

EBot::line EBot::followLine() {
  int ls1 = digitalRead(LightSensor1);
  int ls2 = digitalRead(LightSensor2);
  int ls3 = digitalRead(LightSensor3);

  if (ls1 && ls2 & !ls3) {
    return EBot::LEFT;
  } else if (!ls1 && ls2 && ls3) {
    return EBot::RIGHT;
  } else {
    return EBot::OK;
  }
}

unsigned long EBot::decode() {
  decode_results results;
  unsigned long decode;

  if (irrecv.decode(&results)) {
    decode = results.value;
    irrecv.resume();
    return decode;
  }

  return 0;
}
