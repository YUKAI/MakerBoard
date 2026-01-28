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
    static const uint8_t DCM4_A = 6;
    static const uint8_t DCM4_B = 7;
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
    static void motorPulseCounter();
    void motorPWMBegin();

    class Ultrasonic {
    public:
        Ultrasonic(int Trig_Pin, int Echo_Pin);
        long Ranging();
    private:
        int TP;
        int EP;
    };
};

#endif
