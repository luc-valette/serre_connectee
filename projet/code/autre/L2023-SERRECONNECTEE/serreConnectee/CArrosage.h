#include "CElectrovanne.h"
#include "CPompe.h"
#include <Arduino.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CArrosage.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CArrosage
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

//pin utilisé = 0

class CArrosage{
  public:
    CArrosage(int pin, int seuilFaible, int seuilFort);
    void arroserSiBesoin();
    void changerValeurHumidite(int valeurHumidite=50);
    bool valeurElectrovanne();
    bool valeurPompe();
    int valeurSeuilBas();
    int valeurSeuilHaut();
    int valeurHumiditeActuelle();
    int valeurPin();
  private:
    int pinArrosage;
    int seuilBas;
    int seuilHaut;
    int humiditeActuelle;
    CPompe pompe;
    CElectrovanne electrovanne;
};