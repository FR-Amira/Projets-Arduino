


#include <Arduino.h>
const int led =3;
const int LDR =5;


void setup()
{

Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(LDR,INPUT);
}




void loop()
{

int valLDR=analogRead(LDR);
Serial.println(valLDR);
 int PWM =map(valLDR,49,969,0,255);     //tension de ldr varie entre = 49-969 .cette valeur change par rapport au valeur de R1 ,on utilise methode diviseur de tension 
 // dans ce cas R1 = 10kohm
 analogWrite(led,PWM);
}


