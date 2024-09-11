/*
  LED
  
  ON/OFF on board leds.
  This example code is in the public domain.

  https://github.com/YUKAI/MakerBoard/tree/develop/examples/LED
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
