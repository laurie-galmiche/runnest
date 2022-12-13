#define LED_R PF_1
#define LED_G PF_2
#define LED_B PF_3

void reflex(int numeroTest){
  pinMode(PinButton1,INPUT);
  pinMode(PinButton2,INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT); 
  pinMode(LED_B, OUTPUT);
  int Button1 = digitalRead(PinButton1);
  int Button2 = digitalRead(PinButton2);
  switch (numeroTest) {
    case 1:
      Timer(3,"Lumiere Attendue");
      lumAtt();
      break;  
    case 2:
      Timer(3,"Lumiere Inattendue");
      delay(random(5000)); //on attends au maximum 5sec
      lumAtt();
      break;
    case 3:
      Timer(3,"Son Attendue");
      sonAtt();
      break;
    case 4:
      Timer(3,"Son Inattendue");
      delay(random(5000)); //on attends au maximum 5sec
      sonAtt();      
  }  
}

void lumAtt(){
  digitalWrite(LED_G, HIGH);  
  int Button1 = digitalRead(PinButton1);
  int Button2 = digitalRead(PinButton2); 

  int debut=millis();
  while(Button2==LOW && Button1==LOW){
    Button1 = digitalRead(PinButton1);
    Button2 = digitalRead(PinButton2);
    delay(10);
  }
  int fin = millis();
  digitalWrite(LED_G, LOW);
  DisplayString(20,4,change(fin-debut));
  DisplayString(50,4,"ms");

}

void sonAtt(){
  int note = 659; //Correspond à un E5
  tone(19, note, 1000);

  int Button1 = digitalRead(PinButton1);
  int Button2 = digitalRead(PinButton2);
  int debut=millis();
  while(Button2==LOW && Button1==LOW){
    Button1 = digitalRead(PinButton1);
    Button2 = digitalRead(PinButton2);
    delay(10);
  }
  int fin=millis();
  DisplayString(20,4,change(fin-debut)); 
  DisplayString(50,4,"ms");  
}
