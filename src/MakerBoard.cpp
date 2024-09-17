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

MakerBoardMotor Motor1(MakerBoard::DCM1_A, MakerBoard::DCM1_B);
MakerBoardMotor Motor2(MakerBoard::DCM2_A, MakerBoard::DCM2_B);
MakerBoardMotor Motor3(MakerBoard::DCM3_A, MakerBoard::DCM3_B);
MakerBoardMotor Motor4(MakerBoard::DCM4_A, MakerBoard::DCM4_B);

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
  Motor1.run();
  Motor2.run();
  Motor3.run();
  Motor4.run();
  Motor1.top_cnt++;
  Motor2.top_cnt++;
  Motor3.top_cnt++;
  Motor4.top_cnt++;
  if (Motor1.top_cnt > Motor1.PERIODIC_TIME){
    Motor1.top_cnt = 0;
  }
  if (Motor2.top_cnt > Motor2.PERIODIC_TIME){
    Motor2.top_cnt = 0;
  }
  if (Motor3.top_cnt > Motor3.PERIODIC_TIME){
    Motor3.top_cnt = 0;
  }
  if (Motor4.top_cnt > Notor4.PERIODIC_TIME){
    Motor4.top_cnt = 0;
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