#include "CArrosage.h"

CArrosage::CArrosage(int pin, int seuilFaible, int seuilFort){
  this->pinArrosage=pin;
  this->seuilBas=seuilFaible;
  this->seuilHaut=seuilFort;
  
  pinMode(this->pinArrosage,OUTPUT);
}

void CArrosage::arroserSiBesoin(){
  if (this->humiditeActuelle<this->seuilBas){
    if (!(this->electrovanne.valeurElectrovanne())){
      this->electrovanne.changerValeurActionneur();
      this->pompe.changerValeurActionneur();
      digitalWrite(this->pinArrosage,HIGH);
    }
  }

  else if (this->humiditeActuelle>this->seuilHaut){
    if (this->electrovanne.valeurElectrovanne()){
      this->electrovanne.changerValeurActionneur();
      this->pompe.changerValeurActionneur();
      digitalWrite(this->pinArrosage, LOW);
    }
  }
}

void CArrosage::changerValeurHumidite(int valeurHumidite){
  this->humiditeActuelle=valeurHumidite;
}

bool CArrosage::valeurElectrovanne(){
  return this->electrovanne.valeurElectrovanne();
}

bool CArrosage::valeurPompe(){
  return this->pompe.valeurPompe();
}

int CArrosage::valeurSeuilBas(){
  return this->seuilBas;
}

int CArrosage::valeurSeuilHaut(){
  return this->seuilHaut;
}

int CArrosage::valeurHumiditeActuelle(){
  return this->humiditeActuelle;
}

int CArrosage::valeurPin(){
  return this->pinArrosage;
}