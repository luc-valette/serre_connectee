#include "classeCapteur.h"
#include <ArduinoLowPower.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeHumidite.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser le capteur d'humidité.
// Nom des composants utilises:/
// Historique du fichier:modifié le 14/02/23
/*************************************************/

class classeHumidite : public classeCapteur{
  public:
    classeHumidite();
    uint8_t returnHumidite();
    void changerValeurCapteur();
    uint8_t modifierValeur();
  private:
    uint8_t humidite;
};