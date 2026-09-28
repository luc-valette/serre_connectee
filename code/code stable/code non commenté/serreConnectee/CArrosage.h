#include "CElectrovanne.h"
#include "CPompe.h"
#include <Arduino.h>

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