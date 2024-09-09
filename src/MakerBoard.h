#ifndef MakerBoard_H
#define MakerBoard_H

#include "Arduino.h"
#include "MakerBoardMotor.h"

#define DCM1_A 4
#define DCM1_B 5
#define DCM2_A 2
#define DCM2_B 3
#define DCM3_A 8
#define DCM3_B 9
#define DCM4_A 7
#define DCM4_B 6

#define SERVO1 10
#define SERVO2 11
#define SERVO3 12
#define SERVO4 13

#define GROVE_CON1_SIG A2
#define GROVE_CON1_OPT A3
#define GROVE_CON2_SIG A5
#define GROVE_CON2_OPT A4
#define GROVE_CON3_SIG A6
#define GROVE_CON3_OPT A7
#define LED_RED A0
#define LED_BLUE A1
#define TIMER_FREQUENCY 1

static void motorPinSetup(){
  pinMode(DCM1_A, OUTPUT);
  pinMode(DCM1_B, OUTPUT);
  pinMode(DCM2_A, OUTPUT);
  pinMode(DCM2_B, OUTPUT);
  pinMode(DCM3_A, OUTPUT);
  pinMode(DCM3_B, OUTPUT);
  pinMode(DCM4_A, OUTPUT);
  pinMode(DCM4_B, OUTPUT);
}
static void motorCnt(MakerBoardMotor motor)
{
  if (motor.top_cnt < motor.duration)
    digitalWrite(motor.pinSwitch(), HIGH);
  else if (motor.top_cnt >= motor.duration && motor.top_cnt < PERIODIC_TIME)
    digitalWrite(motor.pinSwitch(), LOW);
}
static void motorRun()
{
  motorCnt(motor1);
  motorCnt(motor2);
  motorCnt(motor3);
  motorCnt(motor4);
  motor1.top_cnt++;
  motor2.top_cnt++;
  motor3.top_cnt++;
  motor4.top_cnt++;
  if (motor1.top_cnt > PERIODIC_TIME)
    motor1.top_cnt = 0;
  if (motor2.top_cnt > PERIODIC_TIME)
    motor2.top_cnt = 0;
  if (motor3.top_cnt > PERIODIC_TIME)
    motor3.top_cnt = 0;
  if (motor4.top_cnt > PERIODIC_TIME)
    motor4.top_cnt = 0;
}
#endif
