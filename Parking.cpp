

#include<Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Initialize the LCD with I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize the servo
Servo gateServo;

// Define pins
const int redLedPin = 4;
const int greenLedPin = 5;
const int servoPin = 6;

// Define parking status
bool parkingAvailable = true;


void updateDisplay() {
  lcd.clear();
  if (parkingAvailable) {
    lcd.setCursor(0, 0);
    lcd.print("Space Available");
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    gateServo.write(0); // Open gate
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Parking Full");
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    gateServo.write(90); // Close gate
  }
}


void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize LEDs
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  // Attach the servo to the pin
  gateServo.attach(servoPin);
  
  // Initial display
  lcd.setCursor(0, 0);
  lcd.print("Parking System");
  delay(2000);
 
}

void loop() {
  // Simulate parking status
  parkingAvailable = !parkingAvailable;
  updateDisplay();
  
  // Wait for a moment
  delay(5000);
}


