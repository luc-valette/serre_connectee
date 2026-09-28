#include "CSigFox.h"

CSigFox::CSigFox():arrosage(0,20,80), fenetre(1,2,20,50), flotteurBas(3), flotteurHaut(4), capteurHumiditeUn(A1,1), capteurHumiditeDeux(0,2), capteurHumiditeTrois(A2,3), capteurTemperatureUn(0,1), capteurTemperatureDeux(A3,2), capteurLuminosite(13){
  this->barreLed=false;
  this->electrovanneVille=false;
  this->demandeRetourMessage=false;
}

void CSigFox::newMessage(sigFoxMessage *message){
  this->booleen[0]=this->demandeRetourMessage*128+this->flotteurBas.valeurFlotteur()*64+this->flotteurHaut.valeurFlotteur()*32+this->electrovanneVille*16+false*8+this->barreLed*4+this->arrosage.valeurElectrovanne()*2+false*1;
  message->etat[0]=booleen[0];
  message->humiditeExterieure=this->capteurHumiditeUn.valeurHumidite();
  message->humiditeInterieure=this->capteurHumiditeDeux.valeurHumidite();
  message->humiditeSol=this->capteurHumiditeTrois.valeurHumidite();
  message->temperatureInterieure=this->capteurTemperatureUn.valeurTemperature();
  message->temperatureExterieure=this->capteurTemperatureDeux.valeurTemperature();
  message->luminosite=this->capteurLuminosite.valeurLuminosite();
}

void CSigFox::newValeurs(){
  this->flotteurBas.changerValeurCapteur();
  this->flotteurHaut.changerValeurCapteur();
  this->capteurHumiditeUn.changerValeurCapteur();
  this->capteurHumiditeDeux.changerValeurCapteur();
  this->capteurHumiditeTrois.changerValeurCapteur();
  this->capteurTemperatureUn.changerValeurCapteur();
  this->capteurTemperatureDeux.changerValeurCapteur();
  this->capteurLuminosite.changerValeurCapteur();
  this->fenetre.changerValeurTemperature(this->capteurTemperatureUn.valeurTemperature());
  this->fenetre.ouvrirSiBesoin(); 
  this->arrosage.changerValeurHumidite(this->capteurHumiditeTrois.valeurHumidite());
  this->arrosage.arroserSiBesoin();
}

void CSigFox::envoiTrame(sigFoxMessage message){
  SigFox.beginPacket();
  SigFox.write(message);
  int ret = SigFox.endPacket();
}

void CSigFox::afficherMessage(sigFoxMessage message){
  Serial.print("Demande de retour message = ");
  Serial.println((message.etat[0]>>7)&1);
  Serial.print("flotteur bas = ");
  Serial.println((message.etat[0]>>6)&1);
  Serial.print("Flotteur haut = ");
  Serial.println((message.etat[0]>>5)&1);
  Serial.print("Electrovanne ville = ");
  Serial.println((message.etat[0]>>4)&1);
  Serial.print("Fenêtre = ");
  Serial.println((message.etat[0]>>3)&1);
  Serial.print("Barre de led = ");
  Serial.println((message.etat[0]>>2)&1);
  Serial.print("Arrosage = ");
  Serial.println((message.etat[0]>>1)&1);
  Serial.print("Décalage = ");
  Serial.println((message.etat[0]>>0)&1);

  Serial.print("\nHumidité extérieure = ");
  Serial.println(message.humiditeExterieure);
  Serial.print("Humidité intérieure = ");
  Serial.println(message.humiditeInterieure);
  Serial.print("Humidité sol = ");
  Serial.println(message.humiditeSol);
  Serial.print("Température extérieure = ");
  Serial.println(message.temperatureExterieure/2-20);
  Serial.print("Température intérieure = ");
  Serial.println(message.temperatureInterieure/2-20);
  Serial.print("Luminosité = ");
  Serial.println(message.luminosite);

  Serial.println("\n---------------------\n");
}