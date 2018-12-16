#include "avdweb_VirtualDelay.h"
#include <Arduino.h>
#include <Streaming.h>

VirtualDelay delay1;

void setup()
{
    Serial.begin(9600);
    Serial << "\ntestOneShot 2s\n";
}

void loop()
{
    DO_ONCE(delay1.start(2000)) // do only one time in the loop
    if (delay1.elapsed())
        Serial << millis() << "ms";
}
