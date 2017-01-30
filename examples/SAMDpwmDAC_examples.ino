#include <Arduino.h>
#include "avdweb_SAMDpwmDAC.h"

SAMDpwmDAC timer3_DAC = SAMDpwmDAC(3, 8, 5);    // 8bit DAC, timer3, pin 5 of the Arduino Uno
SAMDpwmDAC timer4_DAC = SAMDpwmDAC(4, 10, A2);  // 10bit DAC
SAMDpwmDAC timer5_DAC = SAMDpwmDAC(5, 12, SCK); // 12bit DAC 
 
void setup() 
{ timer3_DAC.write(128);  //  8bit DAC, U= 1.65V, f = 187.6kHz,  127/256, 50% duty cycle 
  timer4_DAC.write(512);  // 10bit DAC, U= 1.65V, f = 46.875kHz, 512/1024       ,,
  timer5_DAC.write(2048); // 12bit DAC, U= 1.65V, f = 11,72kHz,  2048/4096      ,,
  analogWrite(4, 128);    //  8bit DAC, U= 1.65V, f = 732Hz,     127/256        ,,
}

void loop() 
{ 
}


