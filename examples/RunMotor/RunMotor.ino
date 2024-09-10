/*
This example run DC motor and servo motor.
Please connect a DC motor to motor pin 1, and connect servo motor to servo motor pin 1.
*/

#include <MakerBoard.h>
#include <Servo.h>
#include <MsTimer2.h>

Servo Servo1;

void setup() {
    pinMode(SERVO1, OUTPUT);
    Servo1.attach(SERVO1);

    // DC motor pin setup
    motorPinSetup();
    // Set DC motor control PWM generation with timer
    MsTimer2::set(TIMER_FREQUENCY, motorPulseCounter);
    MsTimer2::start();

    Serial.begin(38400);
}

void loop() {
    motor1.set(100, FORWARD);       // Motor1 rotate 
    delay(1*1000UL);
    Servo1.write(90);               // Servo motor rotate
    delay(1*1000UL);
    motor1.set(100, BACKWARD);
    delay(1*1000UL);
    Servo1.write(0);
    delay(1*1000UL);
}
