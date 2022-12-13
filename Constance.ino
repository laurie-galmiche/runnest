#define LED_R PF_1

void constance(){
  pinMode(PinButton1,INPUT);
  pinMode(PinButton2,INPUT);
  pinMode(LED_R, OUTPUT);  
    
  int note[] ={659,0,659,0};
  int duration[] = {random(1000,3000), random(2000,5000),random(1000,3000),random(2000,5000)};
  for (int thisnote =0; thisnote<4;thisnote=thisnote+2){
    tone(19,note[thisnote],duration[thisnote]);
    delay(duration[thisnote+1]);
  }
  int Button1 = HIGH;
  int Button2 = HIGH;
  Timer(3,"your time");
  int resultat[] = {0,0,0,0};
  for (int k=0;k<4;k++){
    int debut=millis();
    if (k%2==0){    //on souffle donc faut appuyer sur les bouttons
      while (Button1==HIGH || Button2==HIGH){
        Button1 = digitalRead(PinButton1);
        Button2 = digitalRead(PinButton2);
        digitalWrite(LED_R, HIGH);
        delay(10);
      }
    }
    else{
      while (Button1==LOW && Button2==LOW){
        Button1 = digitalRead(PinButton1);
        Button2 = digitalRead(PinButton2);
        digitalWrite(LED_R, LOW);
        delay(10);
      }   
    }
    int fin=millis();
    resultat[k]=fin-debut;
  }
  for (int k =0;k<4;k++){
    Serial.print(duration[k]);
    Serial.println(resultat[k]);
  }

}
