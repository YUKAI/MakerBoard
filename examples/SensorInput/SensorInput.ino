/*
This example reads analog value from Grove connector pin 1.
Show the value on serial monitor.
*/

#include <MakerBoard.h>

MakerBoard board;

void setup() {
    pinMode(board.GROVE_CON1_SIG, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.print("Grove pin value: ");
    Serial.println(analogRead(board.GROVE_CON1_SIG));
    delay(1*1000UL);
}
