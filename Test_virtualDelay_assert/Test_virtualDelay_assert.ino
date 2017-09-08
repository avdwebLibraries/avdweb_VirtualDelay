#include <Arduino.h>
#include <Streaming.h>
#include <assert.h>
#include "avdweb_VirtualDelay.h"

VirtualDelay delay1, delay2, delay3;

void setup() 
{ Serial.begin(9600);
  delay(1001); // test for start time > 0
  while(millis() <= 2600) test();
  Serial << "\nTest ok";   
}

void loop()
{ 
}

void test() 
{ if(delay1.done(200, 0)) 
  { Serial << "\ndelay 200ms " << millis(); 
    assert((millis() == 1200) || (millis() == 2000));
  }
  if(delay2.done(100, 0)) // test low delay after high delay
  { Serial << "\ndelay 100ms " << millis();
    assert((millis() == 1300) || (millis() == 2100)); 
  }
  if(delay3.done(500, 1)) 
  { Serial << "\ndelay 500ms " << millis();
    assert((millis() == 1800) || (millis() == 2600));
  }
}



