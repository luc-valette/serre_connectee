#include "classeCapteur.h"
#include <ArduinoLowPower.h>
#include <DFRobot_B_LUX_V30B.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeLuminosite.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser le capteur de luminosité.
// Nom des composants utilises:/
// Historique du fichier:modifié le 14/02/23
/*************************************************/

class classeLuminosite : public classeCapteur{
  public:
    classeLuminosite();
    uint32_t returnLuminosite();
    void changerValeurCapteur();
    uint32_t modifierValeur();
  private:
    uint32_t luminosite;
};