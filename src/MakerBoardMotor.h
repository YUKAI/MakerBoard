/**
 * @file MakerBoardMotor.h
 * @author Yoshinobu Obata (yobata@ux-xu.com)
 * @brief motor class for Maker Board
 * @version 0.1
 * @date 2024-09-10
 * 
 * @copyright Copyright (c) Yoshinobu Obata 2024 for Yukai Engineering Inc.
 * 
 */
#ifndef MakerBoardMotor_H
#define MakerBoardMotor_H

#include <Arduino.h>

#define FORWARD 1
#define BACKWARD -1
#define PERIODIC_TIME 20   // Periodic time[ms]

class MakerBoardMotor
{
private:
  volatile uint8_t pin_A;
  volatile uint8_t pin_B;
  volatile int8_t direction = FORWARD;

public:
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
