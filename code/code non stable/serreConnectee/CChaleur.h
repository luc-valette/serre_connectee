#include "CMoteur.h"
#include <Arduino.h>

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