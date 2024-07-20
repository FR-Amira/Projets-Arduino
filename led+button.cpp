
#include <Arduino.h>

 
   // 5ademin bi pul DOWN resister ya3ni 5ademin bi resistan men 3ana w rabtion bouton bi +vcc et res bi masse  donc button ye5dem =1

bool button;

bool box;

int x = 200;

void setup()
{
  pinMode(2, INPUT);  //bouton 
  pinMode(10, OUTPUT);  //lampe
}
          
                  // pg kif tenzel bouton 1 tech3el led w 0 tetfa



void loop()
{
  button = digitalRead(2);  //read bech ed5l fromation li pg asko buton manzel w non
  if (button == 1) {
    digitalWrite(10, HIGH); // write bech yeb3th action li compsant
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(10, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}


 /*

            //pg kif tenzel mara 3l bouton tech3el led donc hatina 1 emt3 bouton fi variable a5er w bi variable haka 5ademna lampe 3l toul


void loop()
{
  button = digitalRead(2);  //read bech ed5l fromation li pg asko buton manzel w non
  if (button == 1) {
    box = 1;
     digitalWrite(10, box);
  }

  }



                      // pg and 



void loop()
{
  button = digitalRead(2);  //read bech ed5l fromation li pg asko buton manzel w non
  if (x > 10 && x < 400) {
  
     digitalWrite(13, 1);
  }

  }





     /// pg   OR

     
void loop()
{
  button = digitalRead(2);  //read bech ed5l fromation li pg asko buton manzel w non
  if (x > 10 || x > 400) {
  
     digitalWrite(13, 1);
  }

  }

  */ 