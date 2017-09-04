#include <Arduino.h>
#include "avdweb_VirtualDelay.h"

const byte ledPin = 13;
bool b;
VirtualDelay singleDelay(millis);

void setup() 
{ pinMode(ledPin, OUTPUT);
}

void loop() 
{ if(singleDelay.done(500)) digitalWrite(ledPin, b=!b); // repeat every 500ms
}

