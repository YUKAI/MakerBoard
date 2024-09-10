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
#ifndef MakerBoard_H
#define MakerBoard_H

#include <Arduino.h>
#include "MakerBoardMotor.h"

class MakerBoard
{
  public:
    // DC motor control IO pins
    static const uint8_t DCM1_A = 4;
    static const uint8_t DCM1_B = 5;
    static const uint8_t DCM2_A = 2;
    static const uint8_t DCM2_B = 3;
    static const uint8_t DCM3_A = 8;
    static const uint8_t DCM3_B = 9;
    static const uint8_t DCM4_A = 7;
    static const uint8_t DCM4_B = 6;
    // Servo motor IO pins
    static const uint8_t SERVO1 = 10;
    static const uint8_t SERVO2 = 11;
    static const uint8_t SERVO3 = 12;
    static const uint8_t SERVO4 = 13;
    // Grove IO pins
    static const uint8_t GROVE_CON1_SIG = A2;
    static const uint8_t GROVE_CON1_OPT = A3;
    static const uint8_t GROVE_CON2_SIG = A5;
    static const uint8_t GROVE_CON2_OPT = A4;
    static const uint8_t GROVE_CON3_SIG = A6;
    static const uint8_t GROVE_CON3_OPT = A7;
    static const uint8_t LED_RED = A0;
    static const uint8_t LED_BLUE = A1;
    static const uint8_t TIMER_FREQUENCY = 1;
    
    void motorPinSetup();
    static void motorRun(MakerBoardMotor motor);
    static void motorPulseCounter();
};

#endif
