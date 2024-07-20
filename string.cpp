

#include <Arduino.h>

String myName= String("My name is Amira") ;
String Prenon=String("Frih");
String Phase;

void setup(){
 Serial.begin(9600);
 Serial.println(myName);
 Serial.println(myName.charAt(0));

Phase=myName + Prenon;
Serial.println(Phase);


}

void loop(){

}

