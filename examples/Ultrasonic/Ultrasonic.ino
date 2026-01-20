/*
  Ultrasonic

  Raging ultrasonic sensor distance measurement example for MakerBoard.
  Please connect an ultrasonic sensor to the ultrasonic sensor pins.

  This example code is in the public domain.

  https://github.com/YUKAI/MakerBoard/tree/develop/examples/Ultrasonic
*/

#include <MakerBoard.h>
MakerBoard board;
MakerBoard::Ultrasonic ultrasonic(board.GROVE_CON1_SIG, board.GROVE_CON1_OPT);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long distance = ultrasonic.Ranging();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}