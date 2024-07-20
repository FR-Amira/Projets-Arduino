

#include<Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<Servo.h>

LiquidCrystal_I2C lcd(32,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int trigPin = 3;
const int echoPin = 2;  
const int red=4;
const int green=5;
Servo sg90;


// defines variables
long duration;
int distance;

void PrintLCD(int distance)
{
   lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Distance:");
  lcd.setCursor(1,1);
  lcd.print(distance);
   delay(1000);
}
int MesureDistance()
{
 // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  return distance;
}

void ParkingFull()
{
    lcd.setCursor(0,0);
    lcd.print("parking full");
    sg90.write(90);
    digitalWrite(red,1);
    digitalWrite(green,0);
     delay(1000);
}
void SpaceAvailable()
{
    sg90.write(0);
    lcd.setCursor(0,0);
    lcd.print("Space Available");
    digitalWrite(red,0);
    digitalWrite(green,1);
    delay(1000);
}

void setup() {
  lcd.init();     // initialize the lcd 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  sg90.attach(6,500,2500);
   lcd.setCursor(1,0);
   lcd.print("Parking:");
  delay(2000);
  sg90.write(90);
 
}
void loop() {

 
distance=MesureDistance();
  // Prints the distance on the LCD I2C
PrintLCD(distance);
 lcd.clear();
 if (distance < 70) {
 ParkingFull();
  } else {
    SpaceAvailable();
  }
  delay(10); // Delay a little bit to improve simulation performance

}











