

#include <Arduino.h>
const int Red=2;
const int PIR=12;
const int green=4;

int valPIR=0;

void setup()
{
pinMode(Red,OUTPUT);
pinMode(PIR,INPUT);
Serial.begin(9600);
}

void loop()
{
 valPIR=digitalRead(PIR);
if(valPIR==1){
    digitalWrite(Red,0);
    digitalWrite(green,1);
    Serial.println("HI! I got you");
}
else {
    digitalWrite(green,0);
    digitalWrite(Red,1);
}
}


