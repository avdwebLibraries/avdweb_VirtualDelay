#include "avdweb_VirtualDelay.h"
#include <Arduino.h>
#include <util/atomic.h>

VirtualDelay delay_ms;
VirtualDelay delay_us(micros);
unsigned long t0_ms, t0_us;

long ms = 1000;
long us = 2000000;

void setMillis(unsigned long ms) {
  extern unsigned long timer0_millis;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { timer0_millis = ms; }
}

void setup() {
  Serial.begin(9600);

  setMillis(-ms); // rollover bug values: -x ... -1
  // setMillis(-1); // rollover bug values: -x ... -1

  t0_ms = millis();
  t0_us = micros();
  Serial.print("\nTest VirtualDelay ms ");
  Serial.print(ms);
  Serila.println("ms");

  Serial.print("\nTest VirtualDelay us ");
  Serial.print(us);
  Serial.println("us");

  Serial.print("\nChanged t0_ms=");
  Serial.print(t0_ms);
  Serial.println("ms");
}

void loop() {
  // do only one time in the loop
  DO_ONCE(delay_ms.start(ms); delay_us.start(us);)

  if (delay_ms.elapsed()) {
    Serial.println();
    Serial.print(millis() - t0_ms);
    Serial.println("ms"); // result is ~ 1021ms
  }
  if (delay_us.elapsed()) {
    Serial.println();
    Serial.print(micros() - t0_us);
    Serial.println("us"); // result is ~ 2021884us
  }
}
