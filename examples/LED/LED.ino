"""
This example ON/OFF leds.
"""

#include <MakerBoard.h>

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
}

void loop() {
    digitalWrite(LED_RED, HIGH);    // Red led ON 
    delay(1*1000UL);
    digitalWrite(LED_BLUE, LOW);    // Blue led OFF
    delay(1*1000UL);
    digitalWrite(LED_RED, LOW);     // Red led OFF 
    delay(1*1000UL);
    digitalWrite(LED_BLUE, HIGH);   // Blue led ON 
    delay(1*1000UL);
}
