#ifndef VirtualDelay_H
#define VirtualDelay_H

class VirtualDelay
{  
public:
  VirtualDelay(unsigned long (*timerFunctionPtr)() = millis); 
  void start(unsigned long delay);
  bool elapsed();
  
  bool running=0;
  unsigned long timeOut, (*timerFunctionPtr)(); 
};

#define DO_ONCE(x) {static bool b; if(!b) {b=1; x;}} 

#endif
