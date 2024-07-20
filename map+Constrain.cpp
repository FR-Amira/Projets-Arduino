
  

# include<Arduino.h>

const int pizPIN=13;  //Piezo
const int photoPIN=A0; // photoresistor
const int led =2;

void setup()
{
 pinMode(pizPIN,OUTPUT);
 pinMode(photoPIN,INPUT);
 Serial.begin(9600);
pinMode(led,OUTPUT);

}


void loop(){

int x,y;
x=analogRead(photoPIN);
Serial.println(x);

y=map(x,100,600,200,360);
y=constrain(y,200,360);
tone(pizPIN,y);



int photoresistorVal = analogRead(photoPIN); // read in photoresistor val
int ledVal = map(photoresistorVal, 0, 1023, 255, 0); // inverse relationship
analogWrite(led, ledVal);

}


