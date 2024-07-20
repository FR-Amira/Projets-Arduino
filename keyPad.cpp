

#include<Arduino.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Define the number of rows and columns on the keypad
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

// Define the keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins
byte rowPins[ROWS] = {13, 12, 11, 10}; 

// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins
byte colPins[COLS] = {9, 8, 7, 6}; 

// Create the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(32, 16, 2);  

void setup(){
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Print a message to the LCD.
  lcd.print("Enter Key:");
}

void loop(){
  // Get the key
  char key = keypad.getKey();
  
  // If a key is pressed
  if (key){
    lcd.clear();
    lcd.print("Key Pressed:");
    lcd.setCursor(0,1); // Move cursor to the second line
    lcd.print(key);
  }
}