/*
  SensorInput

  Reads analog value from Grove connector pin 1.
  Show the value on serial monitor.

  This example code is in the public domain.

  https://github.com/YUKAI/MakerBoard/tree/develop/examples/SensorInput

*/

#include <MakerBoard.h>

MakerBoard board;

void setup() {
  pinMode(board.GROVE_CON1_SIG, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Grove PIN1 value: ");
  Serial.println(analogRead(board.GROVE_CON1_SIG));
  delay(1000);
}
