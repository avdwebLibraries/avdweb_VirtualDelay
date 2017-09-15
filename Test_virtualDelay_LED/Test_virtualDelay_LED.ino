#include <Arduino.h>
#include "avdweb_VirtualDelay.h"
#include <Streaming.h>

const byte ledPin = 13;
bool b;
int i;
VirtualDelay singleDelay; // default = millis

void setup() 
{ pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ singleDelay.start(400); // calls while running are ignored
  if(singleDelay.elapsed()) digitalWrite(ledPin, b=!b); // blink the onboard LED 400ms, 400ms off
  Serial << endl << i++; // since the cpu is not being blocked, printing goes fast
}

