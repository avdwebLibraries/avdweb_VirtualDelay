#include <Arduino.h>
#include <Streaming.h>
#include "avdweb_VirtualDelay.h"

const byte ledPin = 13;

void setup() 
{ pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial << "\nStart at       t = " << millis() << " ";
}

VirtualDelay LEDonDelay(millis), LEDoffDelay(millis), singleDelay(millis);

void loop() 
{ if(LEDonDelay.done(200, LEDoffDelay)) // do after LEDoffDelay  
  { digitalWrite(ledPin, 0);  
    Serial << "\nLED off 800ms, t = " << millis() << " ";
  } 
  if(LEDoffDelay.done(800, LEDonDelay)) // do after LEDonDelay  
  { digitalWrite(ledPin, 1); 
    Serial << "\nLED on  200ms, t = " << millis() << " ";
  }  
  if(singleDelay.done(4000)) // repeat every 4000ms   
  { Serial << "\nsingleDelay t = " << millis() << " ";
  }
  printContinuously();
}

void printContinuously()
{ static int i;
  if(i++>1000) 
  { Serial << "."; 
    i=0;
  }
}
