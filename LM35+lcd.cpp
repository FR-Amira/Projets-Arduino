// LM35 ARDUINO 


#include<Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int val;
const int tempPin = A0; // Temp sensor connected to analog pin A0
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{

    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("hello everyone");
  delay(500);
}
void loop()
{
  lcd.clear();
  val = analogRead(tempPin);
  float temperature = ((( val/1024.0)*500)-50); // fama decalage tab3 tencer cade
  lcd.setCursor(0,0);
  lcd.print("temperature=");
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.setCursor(5,1);
  lcd.print("*C");
  delay(1000);
}



