/*
This program is distributed in the hope that it will be useful, but
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
