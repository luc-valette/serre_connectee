#include "classeCapteur.h"
#include <ArduinoLowPower.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeFlotteur.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser les flotteurs.
// Nom des composants utilises:Vertical float level switch sensor (34764 sur gotronic)
// Historique du fichier:modifié le 14/02/23
/*************************************************/

class classeFlotteur : public classeCapteur{
  public:
    classeFlotteur();
    uint8_t returnFlotteur();
    void changerValeurCapteur();
    uint8_t modifierValeur();
  private:
    uint8_t flotteur;
};