/*
Copyright (C) 2016  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .

Version 10-1-2016
Version 6-9-2017 elapsed(), added start()
Version 19-9-2017 DO_ONCE without class

start         _____|_____________________
                    __________
running       _____|          |__________

elapsed()     ________________|__________

set timeOut   _____|_____________________      

*/

#include <Arduino.h>
#include "avdweb_VirtualDelay.h"

VirtualDelay::VirtualDelay(unsigned long (*timerFunctionPtr)()):
timerFunctionPtr(timerFunctionPtr)
{ 
}

void VirtualDelay::start(unsigned long delay)
{ if(!running)
  { running = 1;
    timeOut = (*timerFunctionPtr)() + delay;
  }
}

bool VirtualDelay::elapsed() 
{ bool pulse = 0;
  if(running)
  { if((*timerFunctionPtr)() >= timeOut) 
    { running = 0;
      pulse = 1; // return 1 just one time  
     }      
  }
  return pulse; 
}







