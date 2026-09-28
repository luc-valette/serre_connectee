#include "CCapteur.h"
#include <Arduino.h>

class CHumidite : public CCapteur{
  public:
    CHumidite(int pin, int typeCapteur);
    uint8_t valeurHumidite();
    void changerValeurCapteur();
    uint8_t lireCapteurUn();
    uint8_t lireCapteurDeux();
    uint8_t lireCapteurTrois();
    int valeurPinHumidite();
  private:
    uint8_t humidite;
    int pinHumidite;
    int type;
};