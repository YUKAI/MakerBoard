/**
 * @file MakerBoard.h
 * @author Yoshinobu Obata (yobata@ux-xu.com)
 * @brief standard library for Maker Board
 * @version 0.1
 * @date 2024-09-10
 * 
 * @copyright Copyright (c) Yoshinobu Obata 2024 for Yukai Engineering Inc.
 * 
 */
#include <Arduino.h>
#include "MakerBoard.h"

MakerBoardMotor motor1(DCM1_A, DCM1_B);
MakerBoardMotor motor2(DCM2_A, DCM2_B);
MakerBoardMotor motor3(DCM3_A, DCM3_B);
MakerBoardMotor motor4(DCM4_A, DCM4_B);
