#include "CMoteur.h"
#include <Arduino.h>

class CChaleur{
  public:
    CChaleur(int pinUn, int pinDeux, int seuilFaible, int seuilFort);
    void ouvrirSiBesoin();
    void changerValeurTemperature(uint8_t valeurTemperature);
    uint8_t valeurTemperatureActuelle();
    int valeurSeuilMax();
    int valeurSeuilMin();
    bool valeurFenetre();
    int valeurPinUnFenetre();
    int valeurPinDeuxFenetre();
  private:
    int pinUnMoteur;
    int pinDeuxMoteur;
    uint8_t temperatureActuelle;
    int seuilMin;
    int seuilMax;
    CMoteur moteur;
};