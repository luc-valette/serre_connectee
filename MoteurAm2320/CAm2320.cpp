#include "CAm2320.h"

CAm2320::CAm2320(){
  this->capteur=Adafruit_AM2320();
  this->capteur.begin();
}

void CAm2320::changerValeurCapteur(){
  this->temperature=(uint8_t)((int)this->capteur.readTemperature());
}

uint8_t CAm2320::valeurTemperature(){
  return this->temperature;
}
