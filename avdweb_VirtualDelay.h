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


class Do_once
{ 
public:
  operator bool ();

private:  
  bool b=0;
};

#define DO_ONCE(x) static Do_once do_once; if(do_once) {x;}

#endif
