/**
 * @file MakerBoard.h
 * @author Yoshinobu Obata (yobata@ux-xu.com)
 * @brief standard library for Maker Board
 * @version 0.1
 * @date 2024-09-10
 * 
 * @copyright Copyright (c) Yoshinobu Obata 2024 for Yukai Engineering Inc.
 * 
 */
#include <Arduino.h>
#include "MakerBoard.h"

MakerBoardMotor motor1(MakerBoard::DCM1_A, MakerBoard::DCM1_B);
MakerBoardMotor motor2(MakerBoard::DCM2_A, MakerBoard::DCM2_B);
MakerBoardMotor motor3(MakerBoard::DCM3_A, MakerBoard::DCM3_B);
MakerBoardMotor motor4(MakerBoard::DCM4_A, MakerBoard::DCM4_B);


void MakerBoard::motorPinSetup(){
  pinMode(this->DCM1_A, OUTPUT);
  pinMode(this->DCM1_B, OUTPUT);
  pinMode(this->DCM2_A, OUTPUT);
  pinMode(this->DCM2_B, OUTPUT);
  pinMode(this->DCM3_A, OUTPUT);
  pinMode(this->DCM3_B, OUTPUT);
  pinMode(this->DCM4_A, OUTPUT);
  pinMode(this->DCM4_B, OUTPUT);
}

/**
 * @brief モーター制御ピンを使ってモーターを回転させる (Rotate the motor using the motor control pin)
 * 
 * @param motor モータークラス (Motor Class)
 */
static void MakerBoard::motorRun(MakerBoardMotor motor)
{
  if (motor.top_cnt < motor.duration)
    digitalWrite(motor.pinSwitch(), HIGH);
  else if (motor.top_cnt >= motor.duration && motor.top_cnt < motor.PERIODIC_TIME)
    digitalWrite(motor.pinSwitch(), LOW);
}

/**
 * @brief モーターを回転させ，パルスのトップをカウントする．このメソッドはTIMER_FREQUENCYでタイマー実行されることを想定している．
 * (Rotate the motor and count the top of the pulses. This method is assumed to be executed by a timer with TIMER_FREQUENCY.)
 * 
 */
static void MakerBoard::motorPulseCounter()
{
  motorRun(motor1);
  motorRun(motor2);
  motorRun(motor3);
  motorRun(motor4);
  motor1.top_cnt++;
  motor2.top_cnt++;
  motor3.top_cnt++;
  motor4.top_cnt++;
  if (motor1.top_cnt > motor1.PERIODIC_TIME)
    motor1.top_cnt = 0;
  if (motor2.top_cnt > motor2.PERIODIC_TIME)
    motor2.top_cnt = 0;
  if (motor3.top_cnt > motor3.PERIODIC_TIME)
    motor3.top_cnt = 0;
  if (motor4.top_cnt > motor4.PERIODIC_TIME)
    motor4.top_cnt = 0;
}
