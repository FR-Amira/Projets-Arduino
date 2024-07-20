  

 
#include <Arduino.h>
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
const int trigPin = 3;
const int echoPin = 2;
const int servoPin = 6;

// Variables for distance measurement
long duration;
int distance;

// Define parking threshold (e.g., 10 cm)
const int threshold = 50;

void updateDisplay(bool parkingAvailable) {
  lcd.clear();
  if (parkingAvailable==true) {
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

int measureDistance() {
  // Clear the Trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the Trig pin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the Echo pin and calculate distance
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}



void setup() {

  
  // Initialize LEDs
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach the servo to the pin
  gateServo.attach(servoPin);
  
  // Initial display
   lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Parking System");
  delay(2000);
  //updateDisplay();
}

void loop() {
  // Measure distance
  distance = measureDistance();
  
  // Check parking status
  if (distance < threshold) {
    // Car detected
    updateDisplay(false);
  } else {
    // No car detected
    updateDisplay(true);
  }
  
  // Wait for a moment
  delay(500);
}


