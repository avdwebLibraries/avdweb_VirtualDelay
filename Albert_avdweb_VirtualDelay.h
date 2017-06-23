/*
VirtualDelay.h

Copyright (C) 2016  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .
 
Version 10-1-2016
*/

#ifndef VirtualDelay_H
#define VirtualDelay_H

class VirtualDelay
{  
public:
  VirtualDelay(unsigned long (*delayFunctionPtr)());
  
  bool proceed(unsigned long periodTime);
  bool done(unsigned long periodTime);
 
private:
  unsigned long nextTime, elapsedTime, (*delayFunctionPtr)(); 
  bool started;
};

#endif
