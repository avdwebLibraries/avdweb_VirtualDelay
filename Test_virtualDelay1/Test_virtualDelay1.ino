#include <Arduino.h>
#include "avdweb_VirtualDelay.h"

const byte ledPin = 13;
bool b;
VirtualDelay singleDelay; // default = millis

void setup() 
{ pinMode(ledPin, OUTPUT);
}

void loop() 
{ if(singleDelay.done(300, 1)) digitalWrite(ledPin, b=!b); // blink the onboard LED
}

