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
*/

#ifndef VirtualDelay_H
#define VirtualDelay_H

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif

class VirtualDelay {
public:
    VirtualDelay(unsigned long (*timerFunctionPtr)() = millis);
    void start(signed long delay);
    bool elapsed();

    bool running = 0;
    unsigned long timeOut, (*timerFunctionPtr)();
};

#define DO_ONCE(x)     \
    {                  \
        static bool b; \
        if (!b) {      \
            b = 1;     \
            x;         \
        }              \
    }

#endif
