# MakerBoard
[メイカーボード](https://prtimes.jp/main/html/rd/p/000000230.000015618.html)を簡単にテキストプログラミングするためのライブラリです．
IOピンの抽象化，DCモーターのPWM生成を行います．

This is MakerBoard standard library.
Abstracts IO pins and generates PWM for DC motors.

# 使い方
examplesに簡単な例があります

## LEDを点滅させる例
```cpp
/*
This example ON/OFF leds.
*/

#include <MakerBoard.h>
MakerBoard board;

void setup() {
    pinMode(board.LED_RED, OUTPUT);
    pinMode(board.LED_BLUE, OUTPUT);
}

void loop() {
    digitalWrite(board.LED_RED, HIGH);    // Red led ON 
    delay(1*1000UL);
    digitalWrite(board.LED_BLUE, HIGH);   // Blue led ON 
    delay(1*1000UL);
    digitalWrite(board.LED_RED, LOW);     // Red led OFF 
    delay(1*1000UL);
    digitalWrite(board.LED_BLUE, LOW);    // Blue led OFF
    delay(1*1000UL);
}
```

## モーターを回転させる例
```cpp
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
}

void loop() {
    motor1.set(100, motor1.FORWARD);    // Motor1 rotate forward. Object motor1 was included from MakerBoard.h
    delay(1*1000UL);
    Servo1.write(90);   // Servo motor rotate
    delay(1*1000UL);

    motor1.set(100, motor1.BACKWARD);   // Motor1 rotate backward 
    delay(1*1000UL);
    Servo1.write(0);
    delay(1*1000UL);
}
```
