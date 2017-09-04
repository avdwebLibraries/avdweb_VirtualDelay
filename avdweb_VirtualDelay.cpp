/*
Copyright (C) 2016  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .
 
Version 10-1-2016
Version 3-9-2017 Completely changed because proceed() was wrong
*/

#include "avdweb_VirtualDelay.h"

VirtualDelay::VirtualDelay(unsigned long (*delayFunctionPtr)()):
delayFunctionPtr(delayFunctionPtr)
{ started = 0; 
}

bool VirtualDelay::done(const unsigned long _delay)
{ bool returnValue = 0;
  if(!started)
  { started = 1;
    delay = _delay;           
    timeOut = (*delayFunctionPtr)() + delay + previousDelay; 
  }
  if(started & (*delayFunctionPtr)() > timeOut) 
  { started = 0;
    returnValue = 1;
  }
  return returnValue;
}

bool VirtualDelay::done(const unsigned long _delay, const VirtualDelay &previousVirtualDelay)
{ previousDelay = previousVirtualDelay.delay;
  //return done(_delay + previousVirtualDelay.delay); // doen is beter maar werkt niet, uitzoeken
  return done(_delay);
}




