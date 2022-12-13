#define PinButton1 PA_4
#define PinButton2 PE_2

void Accueil() {
  //le programme sert à afficher plusieurs choix pour que l'utilisateur choisisse ce qu'il veut faire
  Display(bitmap);
  delay(2000);
  Fill(0x00);

//on affiche les différents choix)
  DisplayString(20,0,"Menu de selection");
  DisplayString(0,1,"-------------------------");
  DisplayString(10,2,"Reflexes");
  DisplayString(10,3,"Temperature");  
  DisplayString(10,4,"Frequence cardiaque");
  DisplayString(10,5,"Constance course");
  DisplayString(10,6,"Reproduction son");
  DisplayString(10,7,"EXIT");

  int numeroLigne = 1;
  
  pinMode(PinButton1,INPUT);
  pinMode(PinButton2,INPUT);
  
  int Button1 = digitalRead(PinButton1);                 //bouton pour descendre
  int Button2 = digitalRead(PinButton2);                 //bouton pour confirmer


  while (Button2==LOW) {                            //tant qu'on a pas confirmer
      Button1 = digitalRead(PinButton1);
      if (Button1==HIGH) {                          //si on appuie sur le bouton1
        //Serial.println(numeroLigne);
        DisplayString(0,numeroLigne+1," ");
        numeroLigne = numeroLigne +1 ;            //on descend d'une ligne
        if (numeroLigne==7){                       //on fait un retour au début
          numeroLigne=1;
        }
        delay(500);
      }      
      DisplayCarac(0,numeroLigne+1,62);
      Button2 = digitalRead(PinButton2);
  }
  delay(1000);
  Fill(0x00);
  switch (numeroLigne) {
    case 1:
      reflex(1);delay(2000);
      reflex(2);delay(2000);
      reflex(3);delay(2000);
      reflex(4);delay(2000);
      Accueil();
      break;
    case 2:
      Temp(100);delay(2000);
      Accueil();
      break;
    case 3:
      readVolt(20);delay(2000);
      Accueil();
      break;
    case 4:
      constance();
      delay(2000);
      Accueil();
      break;
    case 5:
      son(3000,500);
      delay(2000);
      Accueil();
      break;  
    case 6:
      break;                        
 }
 
}
