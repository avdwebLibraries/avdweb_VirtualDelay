#include "avdweb_VirtualDelay.h"
#include <Arduino.h>
#include <Streaming.h>

VirtualDelay delay1, delay2, delay3;

void setup()
{
    Serial.begin(9600);
    Serial << "\ntestSequence";
}

void loop()
{
    if (delay1.elapsed()) // this sequence has a deadlock
    {
        Serial << "\ndelay1 200ms " << millis();
        delay2.start(100);
    }
    if (delay2.elapsed()) {
        Serial << "\ndelay2 100ms " << millis();
        delay3.start(400);
    }
    if (delay3.elapsed()) {
        Serial << "\ndelay3 400ms " << millis();
        delay1.start(200);
    }
    DO_ONCE(delay1.start(200)); // breaks the deadlock, you can start with any
        // delay object you want e.g. delay2.start(0);
}
