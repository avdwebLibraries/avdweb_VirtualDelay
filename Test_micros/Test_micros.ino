#include "avdweb_VirtualDelay.h"

VirtualDelay delay_us(micros);

void setup() { Serial.begin(9600); }

void loop()
{
    DO_ONCE(delay_us.start(1000000)) // 1s
    if (delay_us.elapsed())
        Serial.print(micros());
}
