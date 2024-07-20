

#include<Arduino.h>

const int red=9;
const int blue=6;
const int green=3;

void setup(){
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);

}


void loop(){
int GR=random(0,255);
int GB=random(0,255);
int GG=random(0,255);
analogWrite(red,GR);
analogWrite(blue,GB);
analogWrite(green,GG);
delay(100);

}

