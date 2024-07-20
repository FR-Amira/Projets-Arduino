
   
#include<Arduino.h>
#include <Servo.h>

const int pot=A0;
Servo Sg90;



void setup(){
    pinMode(pot,INPUT);
    Sg90.attach(3);

}

void loop(){
    
    int valPot=analogRead(pot);
     int PwmSp90=map(valPot,0,1023,0,180);
     Sg90.write(PwmSp90);


}

  