/**
 * @file MakerBoard_Motor.cpp
 * @author Yoshinobu Obata
 * @brief motor class for Maker Board
 * @version 0.1
 * @date 2024-09-10
 * Change log:
 * 
 * @copyright Copyright (c) 2024 Yukai Engineering Inc.
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
 * @brief パルス幅を制御するピンを切り替える．
 * (Switch the pin that controls the pulse width.)
 */
int MakerBoardMotor::pinSwitch()
{
  if (this->direction == this->FORWARD)
  {
    digitalWrite(this->pin_B, LOW);
    return this->pin_A;
  }
  if (this->direction == this->BACKWARD)
  {
    digitalWrite(this->pin_A, LOW);
    return this->pin_B;
  }
}
/**
 * @brief モーター回転方向と回転速度を設定する．
 * (Set motor direction and rotation speed rate.)
 * 
 * @param duration 回転速度率 (rotation speed rate) [0% ~ 100%]
 * @param direction 回転方向 (rotation direction) [FOWARD or BACKWARD]
 */
void MakerBoardMotor::set(int16_t duration, int8_t direction)
{
  if (duration < 0)
  {
    this->direction = direction == this->FORWARD ? this->BACKWARD : this->FORWARD;
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
  this->duration = abs(this->PERIODIC_TIME * duration / 100);
}

/**
 * @brief モーター制御ピンを使ってモーターを回転させる． 
 * (Rotate the motor using the motor control pin.)
 * 
 * @param motor モータークラス (Motor Class)
 */
void MakerBoardMotor::run()
{
  if (this->top_cnt < this->duration){
    digitalWrite(this->pinSwitch(), HIGH);
  }
  else if (this->top_cnt >= this->duration && this->top_cnt < this->PERIODIC_TIME){
    digitalWrite(this->pinSwitch(), LOW);
  }
}