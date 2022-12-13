void Timer(int chiffre, char* test){ //chiffre correspond au temps du timer et test au prochain test à faire
  Fill(0x00);
  DisplayString(30,3,"Debut de ");
  DisplayString(20,4,test);

  for (int i=chiffre; i>0;i--){
    SetPageAddress(6);
    DisplayString(60,6,change(i));
    delay(1000); 
   }
  Fill(0x00);
}
