#include "CFlotteur.h"

CFlotteur::CFlotteur(int pin){
  this->pinFlotteur=pin;
  pinMode(this->pinFlotteur,INPUT);
}

bool CFlotteur::valeurFlotteur(){
  return this->flotteur;
}

void CFlotteur::changerValeurCapteur(){
  this->flotteur=this->lireCapteur();
}

bool CFlotteur::lireCapteur(){
  int valeur=digitalRead(this->pinFlotteur);
  if (valeur==0){
    return false;
  }
  else {
    return true;
  }
}

int CFlotteur::valeurPinFLotteur(){
  return this->pinFlotteur;
}