
   ///potentiometre +  buzzer

#include <Arduino.h>

const int portPin= A3;
const int buzzerPin= 4;
const int RedPin=10;
const int GreenPin=12;





void setup()
{
 
 pinMode(portPin,INPUT);
 pinMode(buzzerPin,OUTPUT);
 pinMode(RedPin,OUTPUT);
 pinMode(GreenPin,OUTPUT);

 Serial.begin(9600);

}




void loop()
{
 
  int potvalue=analogRead(portPin);
  tone(buzzerPin,potvalue);

  Serial.println(potvalue);
  if (potvalue < 500)
  {
     digitalWrite(RedPin, HIGH);
     digitalWrite(GreenPin, LOW);
     
  }
  else 
  {
     digitalWrite(GreenPin, HIGH);
     digitalWrite(RedPin, LOW);
  }
    
     }



