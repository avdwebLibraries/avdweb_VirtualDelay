# VirtualDelay
The standard delay() function blocks the Arduino which is not allowed sometimes. Therefore, I have built the VirtualDelay / non-blocking delay library. 
See the article http://www.avdweb.nl/arduino/libraries/virtualdelay.html
Advantages of the VirtualDelay library:
The delay doesn't block anymore.
It is even possible to use multiple delays sequentially.
The interface is straightforward.
The delay time can set in micro-seconds or milli-seconds.
