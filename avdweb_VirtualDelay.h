#ifndef VirtualDelay_H
#define VirtualDelay_H

class VirtualDelay
{  
public:
  VirtualDelay(unsigned long (*delayFunctionPtr)()=millis); 
  bool done(unsigned long _delay, bool last);
  
private:
  unsigned long (*delayFunctionPtr)(); 
  bool delayElapsed=0; 
  static bool started;
  static unsigned long loopTimeOut, loopStartTime;
};
#endif
