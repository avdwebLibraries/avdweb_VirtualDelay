#include <Arduino.h>
#include <Streaming.h>
#include "avdweb_VirtualDelay.h"
#include <util/atomic.h>
#include <Albert.h>

VirtualDelay delay_ms;
VirtualDelay delay_us(micros);
unsigned long t0_ms, t0_us; 

/* change 
 * void start(unsigned long delay) to 
 * void start(signed long delay) because max delay ~ 2^31
*/

unsigned long ms=pow(2,31)+1000; // to large delay, not allowed
unsigned long us=pow(2,31)+100000; // to large delay, not allowed

void setMillis(unsigned long ms)
{ extern unsigned long timer0_millis;
  ATOMIC_BLOCK (ATOMIC_RESTORESTATE) 
  { timer0_millis = ms;
  }
}

void setup() 
{ Serial.begin(9600);

  //setMillis(-ms); // rollover bug values: -x ... -1
  //setMillis(-1); // rollover bug values: -x ... -1
  
  t0_ms=millis();
  t0_us=micros();
  Serial << "\nTest VirtualDelay ms " << ms << "ms"; 
  Serial << "\nTest VirtualDelay us " << us << "us"; 
  Serial << "\nChanged t0_ms=" << t0_ms << "ms"; 
}

void loop() 
{ DO_ONCE // do only one time in the loop 
  ( delay_ms.start(ms);
    delay_us.start(us);    
  ) 
  if(delay_ms.elapsed()) Serial << "\n" << millis()-t0_ms << "ms";  
  if(delay_us.elapsed()) Serial << "\n" << micros()-t0_us << "us";
}




