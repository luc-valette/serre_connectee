#include "CTemperature.h"

/*************************************************/
// Nom du projet: Serre connectée
// Nom du fichier: CTemperature.cpp
// Version: 1.1
// Nom du programmeur: Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création: 2022
// Rôle du fichier: Ce fichier permet de répertorier tous les attributs et méthodes de la classe CTemperature
// Nom des composants utilisés: AM2320, DS18B20
// Historique du fichier: modifié le 31/05/2023
/*************************************************/

// pin utilisés : A3, 11, 12, 5V, gnd

// Nom : CTemperature
// Rôle : constructeur de l'objet de type CTemperature, la méthode utilise la méthode changerValeurCapteur() afin d'avoir la température au moment de la création de l'objet
// Paramètres d'entrée : pin, typeCapteur
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CTemperature::CTemperature(int pin, int typeCapteur){
  this->type = typeCapteur;
  if (this->type == 1){
    this->pinTemperature = -1;
  }
  else{
    this->pinTemperature = pin;
    pinMode(this->pinTemperature, INPUT);
  }
}

// Nom : valeurTemperature
// Rôle : retourne la valeur actuelle de la température
// Paramètres d'entrée : /
// Paramètres de sortie : temperature
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CTemperature::valeurTemperature(){
  return this->temperature;
}

// Nom : changerValeurCapteur
// Rôle : place la nouvelle valeur de temperature l'attribut temperature, elle regarde d'abord quel capteur est demandé puis appelle la fonction adéquate
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CTemperature::changerValeurCapteur(){
  if (this->type == 1){
    this->temperature = this->lireCapteurUn();
  }
  else{
    this->temperature = this->lireCapteurDeux();
  }
}

// Nom : lireCapteurUn
// Rôle : Code qui permet d'utiliser le capteur, il récupère la valeur de la température, l'adapte et la renvoie
// Paramètres d'entrée : /
// Paramètres de sortie : temp
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CTemperature::lireCapteurUn(){
  return (35+20)*2;
}

// Nom : lireCapteurDeux
// Rôle : Code qui permet d'utiliser le capteur, il récupère la valeur de la température, l'adapte et la renvoie
// Paramètres d'entrée : /
// Paramètres de sortie : TemperatureSum
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CTemperature::lireCapteurDeux() {
  OneWire ds(this->pinTemperature);
  byte data[9];
  byte addr[8];

  if (!ds.search(addr)) {
    ds.reset_search();
    return -1000;
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if (addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);

  for (int i = 0; i < 9; i++) {
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB);
  int TemperatureSum = tempRead / 16;

  TemperatureSum += 20;
  TemperatureSum *= 2;
  return (uint8_t)TemperatureSum;
}

// Nom : valeurPinTemperature
// Rôle : retourne le pin utilisé par le capteur de température
// Paramètres d'entrée : /
// Paramètres de sortie : pinTemperature
// Paramètres d'E/S : /
// Valeur de retour : /
int CTemperature::valeurPinTemperature() {
  return this->pinTemperature;
}