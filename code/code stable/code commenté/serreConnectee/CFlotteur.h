#include "CCapteur.h"
#include <Arduino.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CFlotteur.h
// Version:1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc Valette
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CFlotteur, cette classe est une classe fille de la classe CCapteur
// Nom des composants utilisés:C7249
// Historique du fichier:modifié par Luc le 31/05/2023
/*************************************************/

//pin utilisés : 3, 4, 5V

class CFlotteur : public CCapteur{
  public:
    CFlotteur(int pin);
    bool valeurFlotteur();
    void changerValeurCapteur();
    bool lireCapteur();
    int valeurPinFLotteur();
  private:
    bool flotteur;
    int pinFlotteur;
};