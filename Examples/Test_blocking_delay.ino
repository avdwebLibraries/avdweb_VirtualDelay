// Blocking delay 

#include <Arduino.h>
#include <Streaming.h>

const byte ledPin = 13;
int i;

void setup() 
{ pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
  
void loop() 
{ digitalWrite(ledPin, 1); // this comes after 700ms delay  
  delay(100);  
  digitalWrite(ledPin, 0); // this comes after 100ms delay 
  delay(700);   
  Serial << " " << i++; // printing goes slowly
}

  
