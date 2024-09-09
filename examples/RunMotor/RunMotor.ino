"""
MakerBoard library contains pin name, PWM generate function for DC motors.
"""

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
    MsTimer2::set(TIMER_FREQUENCY, motorRun);
    MsTimer2::start();

    Serial.begin(38400);
}

void loop() {
    // Motor1 rotate 
    motor1.set(100, FORWARD);
    delay(1*1000UL);
    Servo1.write(90);
    delay(1*1000UL);
    motor1.set(100, BACKWARD);
    delay(1*1000UL);
    Servo1.write(0);
    delay(1*1000UL);
}
