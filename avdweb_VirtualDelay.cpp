/*
Copyright (C) 2016  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .
 
Version 10-1-2016
Version 6-9-2017 Completely changed 

start at 100
delay         20  10  40  20  10  40  
              +   +   +   +   +   +  
              0   20  30  0   20  30  
loopTimeOut   20  30  70  20  30  70  
loopStartTime 100 100 100 170 170 170 
time          120 130 170 180 200 240 
*/

#include <Albert.h>
#include "avdweb_VirtualDelay.h"
#include <Streaming.h>

VirtualDelay::VirtualDelay(unsigned long (*delayFunctionPtr)()):
delayFunctionPtr(delayFunctionPtr)
{ 
}

bool VirtualDelay::done(unsigned long _delay, bool last)
{ bool returnValue = 0;
  if(!started)
  { started = 1;
    loopStartTime = millis();
  }
  loopTimeOut += _delay; // 1e delay of loop = 20, 2e = 30, 3e = 70, reset at end of loop      
  if((*delayFunctionPtr)() >= (loopTimeOut + loopStartTime)) 
  { if(!delayElapsed) 
    { delayElapsed = 1;
      returnValue = 1; // return 1 just one time  
      if(last) loopStartTime += loopTimeOut;
    }      
  }
  else delayElapsed = 0;
  if(last) loopTimeOut=0;
  return returnValue; 
}

unsigned long VirtualDelay::loopTimeOut=0; 
unsigned long VirtualDelay::loopStartTime=0; 
bool VirtualDelay::started=0;




