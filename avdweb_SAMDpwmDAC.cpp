/*
Copyright (C) 2012  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .

Version 29-1-2017

note *1 SCK, MOSI, MISO are on Arduino Zero SPI header

Timer    Arduino Zero pins              SAM15x15 pins
0 8bit   D3 D18/A4 D17 D4               d[9]  d[5]  d[4]  d[8]              timer not yet implemented
0 16bit  D3 D18/A4                      d[9]  d[5]                          timer not yet implemented
1 8bit   D0 D9 D33 D8 D1 D30            d[11] d[7]  d[31] d[6] d[10] d[27]  timer not yet implemented                
1 16bit  D0 D9 D33                      d[11] d[7]  d[31]                   timer not yet implemented
2 8bit   D13 (D28) D22/MISO*1 D16       d[19] d[15] d[14] d[3]              timer not yet implemented
2 16bit  D13 (D28)                      d[19] d[15]                         timer not yet implemented

3 8bit   D5 D12 D2 D10                  d[17] d[21] d[16] d[20]             timer not yet implemented
3 16bit  D5 D12                         d[17] d[21]
4 8bit   D16/A2 D21/SCL D15/A1 D20/SDA  d[3]  d[25] d[2]  d[24]             timer not yet implemented
4 16bit  D16/A2 D21/SCL                 d[3]  d[25] 
5 8bit   D24/SCK*1 D23/MOSI*1           d[13] d[12]                         timer not yet implemented
5 16bit  D24/SCK*1                      d[13] 
*/

#include "avdweb_SAMDpwmDAC.h"

SAMDpwmDAC::SAMDpwmDAC(byte timerNr, unsigned bits, byte pin):  
SAMDtimer(timerNr, TC_COUNTER_SIZE_16BIT, pin, 0)   
{ prescale = TC_CLOCK_PRESCALER_DIV1; 
  periodCounter = pow(2, bits)-1; // 255, 511, 1023 etc.
  PWcounter = 0;
  init(1);    
}

void SAMDpwmDAC::write(int value) 
{ PWcounter = value;
  init(1);    
}



