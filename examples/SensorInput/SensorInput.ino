/*
This example reads analog value from Grove connector pin 1.
Show the value on serial monitor.
*/

#include <MakerBoard.h>

void setup() {
    pinMode(GROVE_CON1_SIG, INPUT);
    Serial.begin(38400);
}

void loop() {
    Serial.print("Grove pin value: ");
    Serial.println(analogRead(GROVE_CON1_SIG));
    delay(1*1000UL);
}
