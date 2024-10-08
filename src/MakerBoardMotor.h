/**
 * @file MakerBoardMotor.h
 * @author Yoshinobu Obata
 * @brief Motor class for メイカーボード
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
  void run();
};

extern MakerBoardMotor Motor1;
extern MakerBoardMotor Motor2;
extern MakerBoardMotor Motor3;
extern MakerBoardMotor Motor4;

#endif
