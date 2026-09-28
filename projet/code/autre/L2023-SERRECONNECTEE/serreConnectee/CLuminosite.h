#include "CCapteur.h"
#include <Arduino.h>
#include <DFRobot_B_LUX_V30B.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CLuminosite.h
// Version:1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc Valette
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CLuminosite
// Nom des composants utilisés:SEN0390
// Historique du fichier:modifié par Luc le 31/05/2023
/*************************************************/

//pin utilisés : 11, 12, 13, 5V, gnd

class CLuminosite : public CCapteur{
  public:
    CLuminosite(int pin);
    int valeurLuminosite();
    void changerValeurCapteur();
    int lireCapteur();
    int valeurPinLuminosite();
  private:
    int luminosite;
    int pinLuminosite;
};