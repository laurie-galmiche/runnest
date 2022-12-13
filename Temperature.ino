
void affichTemp(float valeur) {
   SetPageAddress(4);
   DisplayString(20,4,change((int)valeur));
   DisplayString(36,4,change(divise(valeur)));
   DisplayString(31,4,",");
   DisplayCarac(50,4,132);
   DisplayString(55,4,"C");   
}

float lireTemp() {
  int sensorValue = analogRead(PB_5);
  float temperature = sensorValue * (100.0 / 1023.0);  
  Serial.println(temperature);
  return temperature;
}

void Temp(int indice) { //indice = nombre de mesures qu'il faut prendre (le test dure indice/2 secondes)
     Timer(5,"Temperature"); //timer de 5s
     DisplayString(10,2,"Temperature");

  for (int i=0;i<indice;i++){
    affichTemp(Moy());
    delay(200);
  }
    Fill(0x00);
}

float Moy(){
  float moy=0.;
    for (int i=0;i<3;i++){
      moy += lireTemp();
      delay(100);
    }
  return moy/3;
}
