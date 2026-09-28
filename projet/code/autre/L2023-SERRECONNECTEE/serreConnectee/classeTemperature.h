#include "classeCapteur.h"
#include <ArduinoLowPower.h>
#include <OneWire.h>
#define ONE_WIRE_BUS 3

extern OneWire oneWire;

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeTemperature.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser le capteur de température.
// Nom des composants utilises:/
// Historique du fichier:modifié le 07/03/23
/*************************************************/

class classeTemperature : public classeCapteur{
  public:
    classeTemperature();
    int16_t returnTemperature();
    void changerValeurCapteur();
    int16_t modifierValeur();
    int16_t getTemp();
  private:
    int16_t temperature;
};