#include "CMoteur.h"
#include <Arduino.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CChaleur.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CChaleur
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

//pin utilisés : 1, 2, gnd

class CChaleur{
  public:
    CChaleur(int pinUn, int pinDeux, int seuilFaible, int seuilFort);
    void ouvrirSiBesoin();
    void changerValeurTemperature(int valeurTemperature = 35);
    int valeurTemperatureActuelle();
    int valeurSeuilMax();
    int valeurSeuilMin();
    bool valeurFenetre();
    int valeurPinUnFenetre();
    int valeurPinDeuxFenetre();
  private:
    int pinUnMoteur;
    int pinDeuxMoteur;
    int temperatureActuelle;
    int seuilMin;
    int seuilMax;
    CMoteur moteur;
};