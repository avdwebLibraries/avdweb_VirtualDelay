#include <Arduino.h>
#include <Streaming.h>
#include "avdweb_VirtualDelay.h"

VirtualDelay delay1, delay2, delay3;

void setup() 
{ Serial.begin(9600);
}

void loop() 
{ if(delay1.done(200, 0)) Serial << "\ndelay 200ms " << millis(); 
  if(delay2.done(100, 0)) Serial << "\ndelay 100ms " << millis(); 
  if(delay3.done(400, 1)) Serial << "\ndelay 400ms " << millis();
}



