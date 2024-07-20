#include<Arduino.h>
#include <Servo.h>




Servo sg90;
int angle;
void setup() {
    //angle=20;
  sg90.attach(4); // pin 
  //sg90.write(angle); // bech ya5o angle mara bark 
}
void loop() 
{ 
 // scan from 0 to 180 degrees
  for(angle =0; angle < 180; angle++)  
  {                                  
    sg90.write(angle);               
    delay(15);     //delas 15ms              
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    sg90.write(angle);           
    delay(15);       
  } 
}
/*


                 /////// servo + button  lazem to93ed nazel 3l button bech ye5dem 


Servo servo_4;

void setup()
{
  pinMode(2, INPUT);
  servo_4.attach(4, 500, 2500);  /// kif zedna 500 et 2500 wala ekmla fiha dora kamla mech na9sa echwaya
}

void loop()
{
  if (digitalRead(2) == 1) {
    servo_4.write(180);
  } else {
    servo_4.write(0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}


*/

