String toAscii(int valeurHex, int taille) {
  int valeurDec = String(valeurHex, DEC).toInt();
}

void TRA(String trame){
  if (trame.equals("COURANTE")){
    Serial.print((char)0x31);
  }else if (trame.equals("SYNCHRO")){
    Serial.print((char)0x32);
  }else if (trame.equals("RAPIDE")){
    Serial.print((char)0x33);
  }
}
void OBJ(){
  Serial.print("G8D0");
}
void REQ(String requete){
  if (requete.equals("ECRITURE")){
    Serial.print((char)0x31);
  }else if (requete.equals("LECTURE")){
    Serial.print((char)0x32);
  }else if (requete.equals("BOTH")){
    Serial.print((char)0x33);
  }  
}
void TYP(String type){
  if (type.equals("DISTANCE1")){
    Serial.print((char)0x31);
  }else if (type.equals("DISTANCE2")){
    Serial.print((char)0x32);
  }else if (type.equals("TEMPERATURE")){
    Serial.print((char)0x33);
  }else if (type.equals("HUMIDITE")){
    Serial.print((char)0x34);
  }else if (type.equals("LUMIERE1")){
    Serial.print((char)0x35);
  }else if (type.equals("COULEUR")){
    Serial.print((char)0x36);
  }else if (type.equals("PRESENCE")){
    Serial.print((char)0x37);
  }else if (type.equals("LUMIERE2")){
    Serial.print((char)0x38);
  }else if (type.equals("MOUVEMENT")){
    Serial.print((char)0x39);
  }else if (type.equals("SON1")){
    Serial.print((char)0x41);
  }else if (type.equals("ENVOIE_DATE")){ //JJ:MM
    Serial.print((char)0x42);
  }else if (type.equals("ENVOIE_ANNEE")){ //AAAA
    Serial.print((char)0x43);
  }else if (type.equals("REQUETE_ACTIONNEUR")){
    Serial.print((char)0x61);
  }else if (type.equals("REQUETE_HEURE1")){ //HH:MM
    Serial.print((char)0x48);
  }else if (type.equals("REQUETE_HEURE2")){ //MM:SS
    Serial.print((char)0x68);
  }else if (type.equals("REQUETE_DATE")){ //JJ:MM
    Serial.print((char)0x70);
  }else if (type.equals("REQUETE_ANNEE")){ //AAAA
    Serial.print((char)0x71);
  }
}
void NUM(){
  //Correspond au numéro du capteur donc normalement 01
  Serial.print((char)0x30);
  Serial.print((char)0x31);
}
void CHK(){
  String liste = Serial.readString();
  int sum = 0;
  int n = liste.length();
  for (int k=0;k<n;k++){
    sum+= (int)(liste[k]);
  }
  Serial.print((char)sum);
}

void convertHex(float nombre){
  if (nombre>16 && nombre<100.){
    Serial.print(int(nombre),HEX);
    Serial.print(",");
    Serial.print(divise(nombre),HEX);
  }else if (nombre >100.){
    Serial.print(int(nombre));
  }
}
