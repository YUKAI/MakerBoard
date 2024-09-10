/**
 * @file MakerBoardMotor.h
 * @author Yoshinobu Obata
 * @brief motor class for Maker Board
 * @version 0.1
 * @date 2024-09-10
 * Change log:
 * 
 * @copyright Copyright (c) 2024 Yukai Engineering Inc.
 * 
 */
#ifndef MakerBoardMotor_H
#define MakerBoardMotor_H

#include <Arduino.h>

class MakerBoardMotor
{
private:
  volatile uint8_t pin_A;
  volatile uint8_t pin_B;
  volatile int8_t direction = this->FORWARD;

public:
  static const int8_t FORWARD = 1;
  static const int8_t BACKWARD = -1;
  static const uint8_t PERIODIC_TIME = 20;
  volatile uint16_t duration;
  volatile uint16_t top_cnt = 0;
  MakerBoardMotor(uint8_t INA, uint8_t INB);
  void set(int16_t duration, int8_t direction);
  int pinSwitch();
};

extern MakerBoardMotor motor1;
extern MakerBoardMotor motor2;
extern MakerBoardMotor motor3;
extern MakerBoardMotor motor4;

#endif
