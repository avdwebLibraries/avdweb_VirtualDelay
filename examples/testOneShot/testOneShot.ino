#include "avdweb_VirtualDelay.h"
#include <Arduino.h>

VirtualDelay delay1;

void setup() {
  Serial.begin(9600);
  Serial.println("\ntestOneShot 2s");
}

void loop() {
  DO_ONCE(delay1.start(2000)) // do only one time in the loop
  if (delay1.elapsed()) {
    Serial.print(millis());
    Serial.println("ms");
  }
}
