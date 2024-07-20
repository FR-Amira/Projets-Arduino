// LM35 ARDUINO 
 


#include<Arduino.h>

int val;
const int tempPin = A0; // Temp sensor connected to analog pin A0

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(tempPin);
  float temperature = ((( val/1024.0)*500)-50); // fama decalage tab3 tencer cade
  Serial.print("temperature=");
  Serial.print(temperature);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}

