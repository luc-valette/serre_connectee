#include "CCapteur.h"
#include <Arduino.h>
#include <DFRobot_B_LUX_V30B.h>

class CLuminosite : public CCapteur{
  public:
    CLuminosite(int pin);
    uint32_t valeurLuminosite();
    void changerValeurCapteur();
    uint32_t lireCapteur();
    int valeurPinLuminosite();
  private:
    uint32_t luminosite;
    int pinLuminosite;
};