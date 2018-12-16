#include "avdweb_VirtualDelay.h"
#include <Arduino.h>
#include <Streaming.h>

void setup() { Serial.begin(9600); }

void loop()
{
    static VirtualDelay delay1, delay2, delay3, delay4, delay5, delay6;
    DO_ONCE(Serial << "\nDO_ONCE 1";
            delay1.start(200); // start sequence delay1 delay2 delay3
            delay4.start(550); // start one-shot delay4
            delay5.start(1250); // start one-shot delay5
    )
    if (delay4.elapsed())
        Serial << "\nONE-SHOT 550ms          " << millis();
    if (delay5.elapsed())
        Serial << "\nONE-SHOT 1250ms         " << millis();

    if (millis() > 2250)
        DO_ONCE(Serial << "\nDO_ONCE 2 2250ms        "
                       << millis()) // test a second DO_ONCE

    delay6.start(750);
    if (delay6.elapsed())
        Serial << "\n  Repeat delay6 750ms   " << millis();

    if (delay1.elapsed()) // sequence with deadlock
    {
        Serial << "\nsequence delay1 200ms   " << millis();
        delay2.start(100);
    }
    if (delay2.elapsed()) {
        Serial << "\nsequence delay2 100ms   " << millis();
        delay3.start(400);
    }
    if (delay3.elapsed()) {
        Serial << "\nsequence delay3 400ms   " << millis();
        delay1.start(200);
    }
}
