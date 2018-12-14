#include "avdweb_VirtualDelay.h"
#include <Albert.h>
#include <Arduino.h>
#include <Streaming.h>
#include <util/atomic.h>

VirtualDelay delay_ms;
VirtualDelay delay_us(micros);
unsigned long t0_ms, t0_us;

long ms = 1000;
long us = 2000000;

void setMillis(unsigned long ms)
{
    extern unsigned long timer0_millis;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { timer0_millis = ms; }
}

void setup()
{
    Serial.begin(9600);

    setMillis(-ms); // rollover bug values: -x ... -1
    // setMillis(-1); // rollover bug values: -x ... -1

    t0_ms = millis();
    t0_us = micros();
    Serial << "\nTest VirtualDelay ms " << ms << "ms";
    Serial << "\nTest VirtualDelay us " << us << "us";
    Serial << "\nChanged t0_ms=" << t0_ms << "ms";
}

void loop()
{
    DO_ONCE // do only one time in the loop
        (delay_ms.start(ms); delay_us.start(us);) if (delay_ms.elapsed()) Serial
        << "\n"
        << millis() - t0_ms << "ms"; // result is ~ 1021ms
    if (delay_us.elapsed())
        Serial << "\n"
               << micros() - t0_us << "us"; // result is ~ 2021884us
}
