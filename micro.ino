void son(int tps,float ref){
  
   Timer(3,"emission du son");
  
 tone(19, 500, 3000);
delay(3000);

  
   Timer(3,"reproduction du son ");
  int counter=0;
  int lastvoltage=0;
  float tpsdebut=millis();
  int seuil=1000;
   float tpsfin=0;
  while((tpsfin-tpsdebut)<tps)
  {
    int voltage = analogRead (PD_1);
    //Serial.println(voltage);
    if (voltage >= seuil && lastvoltage <=seuil)
    {
      counter+=1;
    }
    lastvoltage=voltage;
    tpsfin=millis();
  }
  float frequence=counter*1000/tps;
  Serial.println(frequence);

   DisplayString(20,6,"            ");
             DisplayString(20,3,change(int(frequence)));
             DisplayString(50,3,"Hz");


    float erreur=(abs(ref-frequence)/ref)*100;
               float pourcentage=100- erreur;
                 if(pourcentage<0)
                 {
                     pourcentage=0;
                 }
 Serial.println(pourcentage);
       DisplayString(20,6,"            ");
             DisplayString(20,6,change(int(pourcentage)));
             DisplayCarac(50,6,37);


}
