#include "CChaleur.h"

CChaleur::CChaleur(int pinUn, int pinDeux, int seuilFaible, int seuilFort){
  this->pinUnMoteur=pinUn;
  this->pinDeuxMoteur=pinDeux;
  this->seuilMax=seuilFort;
  this->seuilMin=seuilFaible;

  pinMode(this->pinUnMoteur,OUTPUT);
  pinMode(this->pinDeuxMoteur,OUTPUT);
}

void CChaleur::ouvrirSiBesoin(){
  if (this->temperatureActuelle>this->seuilMax){
    if (!(this->moteur.valeurMoteur())){
      this->moteur.changerValeurActionneur();
      digitalWrite(this->pinUnMoteur,LOW); 
      digitalWrite(this->pinDeuxMoteur,HIGH);
      Serial.println("J'allume le moteur");
      delay(30*1000);
      Serial.println("J'éteins le moteur");
      digitalWrite(this->pinUnMoteur,HIGH);
      digitalWrite(this->pinDeuxMoteur,HIGH);
    }
  }

  else if (this->temperatureActuelle<this->seuilMin){
    if (this->moteur.valeurMoteur()){
      this->moteur.changerValeurActionneur();
      digitalWrite(this->pinUnMoteur,HIGH); 
      digitalWrite(this->pinDeuxMoteur,LOW);
      Serial.println("J'allume le moteur");
      delay(30*1000);
      Serial.println("J'éteins le moteur");
      digitalWrite(this->pinUnMoteur,HIGH);
      digitalWrite(this->pinDeuxMoteur,HIGH);
    }
  }
}

void CChaleur::changerValeurTemperature(int valeurTemperature){
  this->temperatureActuelle=valeurTemperature;
}

int CChaleur::valeurTemperatureActuelle(){
  return this->temperatureActuelle;
}

int CChaleur::valeurSeuilMax(){
  return this->seuilMax;
}

int CChaleur::valeurSeuilMin(){
  return this->seuilMin;
}

bool CChaleur::valeurFenetre(){
  return this->moteur.valeurMoteur();
}

int CChaleur::valeurPinUnFenetre(){
  return this->pinUnMoteur;
}

int CChaleur::valeurPinDeuxFenetre(){
  return this->pinDeuxMoteur;
}