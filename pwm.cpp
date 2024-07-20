
 // 1 methode 
#include <Arduino.h>

float val_pot = 0;
float val_PWM = 0;



void setup() {
  pinMode(A1,INPUT);
  pinMode(5,OUTPUT);


}


void loop() {
   while(1) {
      val_pot = analogRead(A1);
      val_PWM = val_pot / 4;  /// potensiomtre valeur entre 0 et 1023 et PWM entre 0 et 255 donc 1023/4=255
      analogWrite(5,val_PWM);

     
  }
}


     ///////////////////2 programme /////////////

/*


#include <Arduino.h>

const int potPIN=A1;
const int ledPIN = 5;

int PotValue;
int PwmValue;

void setup() {

pinMode(potPIN,INPUT);
pinMode(ledPIN,OUTPUT);
Serial.begin(9600);
}
void loop() {

    PotValue=analogRead(potPIN);
    Serial.print("PWMValue == ");
    PwmValue=map(PotValue, 0, 1023, 0, 255);  /// MAP bech ya3ml transfer men 0 1023 li 0 255
    Serial.println(PwmValue);
    analogWrite(ledPIN,PwmValue);
}





     ///////////////////3 programme /////////////



#include <Arduino.h>


const int ledPIN = 5;


void setup() {


pinMode(ledPIN,OUTPUT);

}
void loop() {

  for(int i=0;i<=255;i++)
  {
        analogWrite(ledPIN,i);
        delay(100);
  }

  
  for(int j=255;j>=0;j--)
  {
        analogWrite(ledPIN,j);
        delay(100);
  }
   
  
}

*/

