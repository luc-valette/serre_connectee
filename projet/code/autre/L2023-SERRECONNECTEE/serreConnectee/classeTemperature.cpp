#include "classeTemperature.h"
OneWire oneWire(ONE_WIRE_BUS);
OneWire ds(A3);
//Pin A3 utilisé

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeTemperature.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser le capteur de température.
// Nom des composants utilises:/
// Historique du fichier:modifié le 07/03/2023
/*************************************************/

// Nom : classeTemperature
// Rôle : Constructeur de la classe classeTemperature
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
classeTemperature::classeTemperature(){
  this->temperature=modifierValeur();
}

// Nom : returnTemperature
// Rôle : retourne la valeur de la température
// Paramètres d'entrée : /
// Paramètres de sortie : valeur de la température
// Paramètres d'E/S : /
// Valeur de retour : /
int16_t classeTemperature::returnTemperature(){
  return this->temperature;
}

// Nom : changerValeurCapteur
// Rôle : place la nouvelle valeur de temperature l'attribut température
// Paramètres d'entrée : /
// Paramètres de sortie : valeur de la température
// Paramètres d'E/S : /
// Valeur de retour : /
void classeTemperature::changerValeurCapteur(){
  this->temperature=modifierValeur();
}

// Nom : modifierValeur
// Rôle : Récupère la valeur du capteur et la retourne
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : valeur de la température sur 8 bits
int16_t classeTemperature::modifierValeur(){
  int16_t temp;
  float temperature = getTemp();
  delay(1000);
  temperature = getTemp();
  temperature = temperature * 100;
  temp = (int16_t) temperature;
  return temp;
}

// Nom : getTemp
// Rôle : Code qui permet d'utiliser le capteur, il retourne la température
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : valeur de la lumière en uint8_t
int16_t classeTemperature::getTemp(){
  //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad


  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;
}