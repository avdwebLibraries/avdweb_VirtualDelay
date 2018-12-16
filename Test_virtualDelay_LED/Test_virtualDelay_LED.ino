#include "avdweb_VirtualDelay.h"
#include <Arduino.h>

const byte ledPin = 13;
bool b;
VirtualDelay singleDelay; // default = millis

void setup() { pinMode(ledPin, OUTPUT); }

void loop()
{
    singleDelay.start(400); // calls while running are ignored
    if (singleDelay.elapsed())
        digitalWrite(ledPin, b = !b); // blink the onboard LED 400ms, 400ms off
}
