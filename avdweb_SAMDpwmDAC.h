/*
Copyright (C) 2012  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .

Version 29-1-2017
*/

#ifndef SAMDpwmDAC_H
#define SAMDpwmDAC_H

#include <avdweb_SAMDtimer.h>

class SAMDpwmDAC : public SAMDtimer   
{ public:
    SAMDpwmDAC(byte timerNr, unsigned bits, byte pin); 
    void write(int value);
};
#endif

