#include "Arduino.h"
#include <EBot.h>

IRrecv irrecv(receiverpin);

EBot::EBot() {
}

EBot::~EBot() {
  servo.detach();
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

void EBot::stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void EBot::rightWheelForward() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void EBot::rightWheelForward(int speed) {
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
  analogWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void EBot::leftWheelForward() {
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void EBot::leftWheelForward(int speed) {
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
  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


//-----------------------------


void EBot::forward() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
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
  long distance = 0.0;
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trig, LOW);
  digitalWrite(Trig, HIGH);
  distance = pulseIn(Echo, HIGH);

  return distance / 29 / 2;
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
  unsigned long decode = 0;

  if (irrecv.decode(&results)) {
    decode = results.value;
    irrecv.resume();
    if (decode == 4294967295) {
      decode = 0;
    }
  }

  return decode;
}
