
void readVolt(int duree){
  float trigger = 900; //Ã  initialiser en fonction de ce qu'on a
  float lastValue = 0.0;
  float time0 = 0.0;
  float lasttime = 0.0;

  Timer(3,"Frequence cardiaque");
  for (int i=0;i<duree;i=i+0.01){
      int sensorValue = analogRead(PD_2);
       //Serial.println(sensorValue);

      if (sensorValue >= trigger && lastValue <=trigger){

            // Serial.println(sensorValue);
            //Serial.println(time0-lasttime);

            float value=(1000*60/(time0-lasttime));
            Serial.println(value);


            lasttime = time0;         
           
             DisplayString(20,6,"            ");
             DisplayString(20,6,change(int(value)));
             DisplayString(40,6,",");
             DisplayString(45,6,change(divise(value)));
             DisplayString(70,6,"bpm");
            }
             
      
      lastValue = sensorValue;

      delay(10); 
      time0=time0+10;
  }
}
