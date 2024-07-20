
#include <Arduino.h>
const int ledPin=12;
const int buttonPin = 2;
const int longDelay = 1000;
const int shortDelay = 500;



// PUL UP resistor cad bech ne5demo resistance eli fi arduino donc buton yetrbat bi masse w buton kif yebda manzol = 0

void setup()
{
 
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);



}




void loop()
{
 
  bool buttonstat= digitalRead(buttonPin);
   if(buttonstat==0)   // mest3mlin PULL UP donc button fi 0 ya3ni manzol
     {
        digitalWrite(ledPin, HIGH);
        delay(longDelay);
        digitalWrite(ledPin, LOW);
        delay(longDelay);
    
        
     }
     else{
  
        digitalWrite(ledPin, HIGH);
        delay(shortDelay);
        digitalWrite(ledPin, LOW);
        delay(shortDelay);
    
        
     }
     }


