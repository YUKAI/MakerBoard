/*
  RunMotor

  Run DC motor and servo motor.
  Please connect a DC motor to motor pin 1, and connect servo motor to servo motor pin 1.

  This example code is in the public domain.

  https://github.com/YUKAI/MakerBoard/tree/develop/examples/RunMotor
*/
#include <MakerBoard.h>
#include <Servo.h>
#include <MsTimer2.h>

MakerBoard board;
Servo Servo1;

void setup() {
  pinMode(board.SERVO1, OUTPUT);
  Servo1.attach(board.SERVO1);

  board.motorPWMBegin();
}

void loop() {
  motor1.set(100, motor1.FORWARD);    // Motor1 rotate forward. Object motor1 was included from MakerBoard.h
  delay(1*1000UL);
  Servo1.write(90);   // Servo motor rotate
  delay(1*1000UL);

  motor1.set(50, motor1.BACKWARD);   // Motor1 rotate backward 
  delay(1*1000UL);
  Servo1.write(0);
  delay(1*1000UL);
}
