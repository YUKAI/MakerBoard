/*
This example run DC motor and servo motor.
Please connect a DC motor to motor pin 1, and connect servo motor to servo motor pin 1.
*/

#include <MakerBoard.h>
#include <Servo.h>
#include <MsTimer2.h>

MakerBoard board;
Servo Servo1;

void setup() {
    pinMode(board.SERVO1, OUTPUT);
    Servo1.attach(board.SERVO1);

    // DC motor pin setup
    board.motorPinSetup();
    // Set DC motor control PWM generation with timer
    MsTimer2::set(board.TIMER_FREQUENCY, board.motorPulseCounter);
    MsTimer2::start();

    Serial.begin(38400);
}

void loop() {
    motor1.set(100, motor1.FORWARD);    // Motor1 rotate forward
    delay(1*1000UL);
    Servo1.write(90);   // Servo motor rotate
    delay(1*1000UL);

    motor1.set(100, motor1.BACKWARD);   // Motor1 rotate backward 
    delay(1*1000UL);
    Servo1.write(0);
    delay(1*1000UL);
}
