/**
 * @file MakerBoard.h
 * @author Yoshinobu Obata
 * @brief standard library for Maker Board
 * @version 0.1
 * @date 2024-09-10
 * Change log:
 * 
 * @copyright Copyright (c) 2024 Yukai Engineering Inc.
 * 
 */
#include <Arduino.h>
#include "MakerBoard.h"
#include <MsTimer2.h>

MakerBoardMotor motor1(MakerBoard::DCM1_A, MakerBoard::DCM1_B);
MakerBoardMotor motor2(MakerBoard::DCM2_A, MakerBoard::DCM2_B);
MakerBoardMotor motor3(MakerBoard::DCM3_A, MakerBoard::DCM3_B);
MakerBoardMotor motor4(MakerBoard::DCM4_A, MakerBoard::DCM4_B);

/**
 * @brief DCモーターのピン設定．GPIO２〜GPIO９ピンが使用される．
 * (Configure the DC motor driver pins from GPIO2 to GPIO9.)
 */
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
 * @brief モーターを回転させ，パルスのトップをカウントする．このメソッドはTIMER_FREQUENCYでタイマー実行されることを想定している．
 * (Rotate the motor and count the top of the pulses. This method is assumed to be executed by a timer with TIMER_FREQUENCY.)
 * 
 */
static void MakerBoard::motorPulseCounter()
{
  motor1.run();
  motor2.run();
  motor3.run();
  motor4.run();
  motor1.top_cnt++;
  motor2.top_cnt++;
  motor3.top_cnt++;
  motor4.top_cnt++;
  if (motor1.top_cnt > motor1.PERIODIC_TIME){
    motor1.top_cnt = 0;
  }
  if (motor2.top_cnt > motor2.PERIODIC_TIME){
    motor2.top_cnt = 0;
  }
  if (motor3.top_cnt > motor3.PERIODIC_TIME){
    motor3.top_cnt = 0;
  }
  if (motor4.top_cnt > motor4.PERIODIC_TIME){
    motor4.top_cnt = 0;
  }
}

/**
 * @brief DCモーターのPWMを生成する．(Set time for DC motor PWM control.)
 * 
 */
void MakerBoard::motorPWMBegin(){
  // Set DC motor control PWM generation with timer
  this->motorPinSetup();
  MsTimer2::set(this->TIMER_FREQUENCY, this->motorPulseCounter);
  MsTimer2::start();
}