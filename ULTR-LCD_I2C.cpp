

#include<Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int trigPin = 3;
const int echoPin = 2;  
// defines variables
long duration;
int distance;

void PrintLCD(int distance)
{
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Distance:");
  lcd.setCursor(1,1);
  lcd.print(distance);
}
void setup() {
  lcd.init();     // initialize the lcd 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
}
void loop() {

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

  // Prints the distance on the LCD I2C


PrintLCD(distance);


}

