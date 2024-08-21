/**
 * avdweb_VirtualDelay.h
 *
 * avdweb_VirtualDelay Library Multiple delays without blocking code execution.
 * ============================================================================
 *
 * Sources
 * -------
 * https://github.com/avandalen/VirtualDelay
 *
 * Website
 * -------
 * http://www.avdweb.nl/arduino/libraries/virtualdelay.html
 *
 * License
 * --------
 * SPDX: GPL-3.0-or-later
 *
 *  avdweb_VirtualDelay Library Multiple delays without blocking code execution.
 *
 *  Copyright (C) 2018-2024 Albert van Dalen <http://www.avdweb.nl>
 *  Copyright (C) 2024 Abhijit Bose (aka. Boseji) :contributor:
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

#define DO_ONCE(x)                                                             \
  {                                                                            \
    static bool b;                                                             \
    if (!b) {                                                                  \
      b = 1;                                                                   \
      x;                                                                       \
    }                                                                          \
  }

#endif
