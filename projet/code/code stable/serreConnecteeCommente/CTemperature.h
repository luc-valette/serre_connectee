#include "CCapteur.h"
#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 3

extern OneWire oneWire;

/*************************************************/
// Nom du projet: Serre connectée
// Nom du fichier: CTemperature.h
// Version: 1.1
// Nom du programmeur: Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création: 2022
// Rôle du fichier: Ce fichier permet de répertorier tous les attributs et méthodes de la classe CTemperature
// Nom des composants utilisés: AM2320, DS18B20
// Historique du fichier: modifié le 31/05/2023
/*************************************************/

// pins utilisés : A3, 11, 12, 5V, gnd

class CTemperature : public CCapteur{
  public:
    CTemperature(int pin, int typeCapteur);
    uint8_t valeurTemperature();
    void changerValeurCapteur();
    uint8_t lireCapteurUn();
    uint8_t lireCapteurDeux();
    int valeurPinTemperature();

  private:
    uint8_t temperature;
    int pinTemperature;
    int type;
};