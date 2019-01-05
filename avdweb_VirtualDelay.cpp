/*
Copyright (C) 2016  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version. This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at
http://www.gnu.org/licenses .

AUTHOR: Albert van Dalen
WEBSITE: http://www.avdweb.nl/arduino/libraries/virtualdelay.html

HISTORY:
1.0.0   10-1-2016
1.0.1   6-9-2017 elapsed(), added start()
1.0.2   19-9-2017 DO_ONCE without class
1.0.3   19-9-2017 fix rollover bug
1.0.5   some changes made by TADT1909

start         _____|_____________________
                    __________
running       _____|          |__________

elapsed()     ________________|__________

set timeOut   _____|_____________________

*/

#include "avdweb_VirtualDelay.h"

VirtualDelay::VirtualDelay(
    unsigned long (*timerFunctionPtr)())
    : timerFunctionPtr(timerFunctionPtr)
{
}

void VirtualDelay::start(signed long delay) // 0...2^31
{
    if (!running) {
        running = 1;
        timeOut = (*timerFunctionPtr)() + abs(delay);
    }
}

bool VirtualDelay::elapsed()
{
    if (running) {
        // bug
        // if((signed long)(*timerFunctionPtr)() >= timeOut)
        // not the same as
        if ((signed long)((*timerFunctionPtr)() - timeOut) >= 0) {
            // fix rollover bug:
            // https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover/12588#12588
            running = 0;
            return 1; // timer is elapsed
        }
    }
    return 0; // still in delay timer
}
