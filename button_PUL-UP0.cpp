
#include <Arduino.h>
bool butonstate;

// PUL UP resistor cad bech ne5demo resistance eli fi arduino donc buton yetrbat bi masse w buton kif yebda manzol = 0

void setup()
{

pinMode(2,INPUT_PULLUP); // bech norbeto button em3 resistan emt3 arduino
Serial.begin(9600);
}




void loop()
{

butonstate = digitalRead(2);
Serial.println(butonstate);
}


