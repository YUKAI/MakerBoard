# MakerBoard
Arduino互換機の[メイカーボード](https://prtimes.jp/main/html/rd/p/000000230.000015618.html)を簡単にテキストプログラミングするためのライブラリです．
IOピンの抽象化，DCモーターのPWM生成を行います．Arduino UnoやArduino pro miniでも使用いただけます．
ピンアサインは[MakerBoard.h](https://github.com/YUKAI/MakerBoard/blob/main/src/MakerBoard.h)をご確認ください．

This library abstracts IO pins and generates PWM for DC motors.
It can also be used with Arduino Uno, Arduino pro mini and so on. 
Please check [MakerBoard.h](https://github.com/YUKAI/MakerBoard/edit/main/src/MakerBoard.h) for pin assignment.

# 使い方 How to Use
examplesに簡単な例があります

## LEDを点滅させる例 Blink LED example
```cpp
#include <MakerBoard.h>
MakerBoard board;

void setup() {
  pinMode(board.LED_RED, OUTPUT);
  pinMode(board.LED_BLUE, OUTPUT);
}

void loop() {
  digitalWrite(board.LED_RED, HIGH);    // Red led ON 
  delay(1000);
  digitalWrite(board.LED_BLUE, HIGH);   // Blue led ON 
  delay(1000);
  digitalWrite(board.LED_RED, LOW);     // Red led OFF 
  delay(1000);
  digitalWrite(board.LED_BLUE, LOW);    // Blue led OFF
  delay(1000);
}

```

## モーターを回転させる例 Drive motor
DCモーターを制御するためにPWMをTimer2で生成しています．そのため，Grove スピーカーなどのタイマーを使用するライブラリと干渉する恐れがあります．併用する場合はご注意ください．

PWM is generated using Timer2 to control the DC motor. Therefore, there is a risk of interference with libraries that use timers such as Grove speakers. Please be careful when using them together.
```cpp
#include <MakerBoard.h>
#include <Servo.h>
#include <MsTimer2.h>

MakerBoard board;
Servo servo1;

void setup() {
  pinMode(board.SERVO1, OUTPUT);
  servo1.attach(board.SERVO1);

  board.motorPWMBegin();
}

void loop() {
  Motor1.set(100, Motor1.FORWARD);    // Motor1 rotate forward. Object motor1 was included from MakerBoard.h
  delay(1000);
  servo1.write(90);   // Servo motor rotate
  delay(1000);

  Motor1.set(50, Motor1.BACKWARD);   // Motor1 rotate backward 
  delay(1000);
  servo1.write(0);
  delay(1000);
}

```
