#include "CCapteur.h"
#include <Arduino.h>

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