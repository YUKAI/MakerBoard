"""
This example read analog value from Grove connector pin 1.
"""

#include <MakerBoard.h>

void setup() {
    pinMode(GROVE_CON1_SIG, INPUT);
    Serial.begin(38400);
}

void loop() {
    Serial.print("Grove pin value: ")
    Serial.println(analogRead(GROVE_CON1_SIG));
    delay(1*1000UL);
}
