
#include "iseplogo128.h"
#include "logo2.h"


#define INVERTDISPLAY                   0xA7
void setup() {
  InitI2C();
  InitScreen();
  Serial.begin(9600);

  
  // void test_fft(); // La fonction test_fft disponible dans le fichier fft.ino montre comment utiliser la fft
  //delay(2000);
  //Fill(0x00);
  //Display(bitmap);
 // InvertDisplay(1);

 // Accueil();
  //readVolt(10000);
 // reflex(1);          
  //Temp(100);
  //DisplayString(0,5,"Bouh");
constance();
//son(3000,500);

}

void loop() {
  
}
