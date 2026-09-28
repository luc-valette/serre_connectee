#include "CHumidite.h"

CHumidite::CHumidite(int pin, int typeCapteur){
  this->type=typeCapteur;
  if (this->type==2){
    this->pinHumidite=-1;
  }
  else{
    this->pinHumidite=pin;
    pinMode(this->pinHumidite,INPUT);
  }
}

uint8_t CHumidite::valeurHumidite(){
  return this->humidite;
}

void CHumidite::changerValeurCapteur(){
  if (this->type==1) {
    this->humidite=this->lireCapteurUn();
  } 
  else if (this->type==2){
    this->humidite=this->lireCapteurDeux();
  } 
  else{
    this->humidite=this->lireCapteurTrois();
  }
}

uint8_t CHumidite::lireCapteurUn(){
  uint8_t valeurHumidite=100-(int)analogRead(this->pinHumidite)/9.0;
  return valeurHumidite;
}

uint8_t CHumidite::lireCapteurDeux(){
  return 50;
}

uint8_t CHumidite::lireCapteurTrois(){
  uint8_t valeurHumidite=(int)(analogRead(this->pinHumidite)/10.23);
  return valeurHumidite;
}

int CHumidite::valeurPinHumidite(){
  return this->pinHumidite;
}