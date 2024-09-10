/**
 * @file MakerBoard_Motor.cpp
 * @author Yoshinobu Obata (yobata@ux-xu.com)
 * @brief motor class for Maker Board
 * @date 2024-09-10
 * 
 * @copyright Copyright (c) Yoshinobu Obata 2024 for Yukai Engineering Inc.
 * 
 */
#include "MakerBoardMotor.h"
#include <Arduino.h>

MakerBoardMotor::MakerBoardMotor(uint8_t INA, uint8_t INB)
{
  this->pin_A = INA;
  this->pin_B = INB;
}

/**
 * パルス幅を制御するピンを切り替える．HIGHを入力するピンを返す．
 */
int MakerBoardMotor::pinSwitch()
{
  if (this->direction == FORWARD)
  {
    digitalWrite(this->pin_B, LOW);
    return this->pin_A;
  }
  if (this->direction == BACKWARD)
  {
    digitalWrite(this->pin_A, LOW);
    return this->pin_B;
  }
}
/**
 * @brief 
 * 
 * @param duration rotation speed [0% ~ 100%]
 * @param direction rotation direction [FOWARD or BACKWARD]
 */
void MakerBoardMotor::set(int16_t duration, int8_t direction)
{
  if (duration < 0)
  {
    this->direction = direction == FORWARD ? BACKWARD : FORWARD;
  }
  else
  {
    this->direction = direction;
  }
  if (duration > 100){
    duration = 100;
  }else if(duration < -100){
    duration = -100;
  }
  this->duration = abs(PERIODIC_TIME * duration / 100);
}

