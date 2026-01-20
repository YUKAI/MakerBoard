/**
 * @file MakerBoard.h
 * @author Yoshinobu Obata
 * @brief Standard library for メイカーボード
 * @version 1.0.3
 * @date 2026-01-20
 * Change log:
 * 2026-01-20: Added Ultrasonic class for ultrasonic sensor support.
 * 
 * @copyright Copyright (c) 2026 Yukai Engineering Inc.
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
  if (Motor4.top_cnt > Motor4.PERIODIC_TIME){
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

MakerBoard::Ultrasonic::Ultrasonic(int Trig_Pin, int Echo_Pin)
{
  pinMode(Trig_Pin,OUTPUT);
  pinMode(Echo_Pin,INPUT);
  TP = Trig_Pin;
  EP = Echo_Pin;
}

long MakerBoard::Ultrasonic::Ranging(){
  digitalWrite(TP, LOW);
  delayMicroseconds(2);
  digitalWrite(TP, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP, LOW);

  long duration = pulseIn(EP,HIGH);
  long distance_cm = duration /29 / 2 ;
  return distance_cm;
}