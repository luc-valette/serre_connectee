#include <SigFox.h>
#include <Arduino.h>

#include "CFlotteur.h"
#include "CHumidite.h"
#include "CLuminosite.h"
#include "CTemperature.h"
#include "CArrosage.h"
#include "CChaleur.h"

typedef struct __attribute__ ((packed)) sigFoxMessage{
  char etat[1];
  uint8_t humiditeExterieure;
  uint8_t humiditeInterieure;
  uint8_t humiditeSol;
  uint8_t temperatureExterieure;
  uint8_t temperatureInterieure;
  uint32_t luminosite;
}sigFoxMessage;

class CSigFox{
  public:
    CSigFox();
    void nouveauMessage(sigFoxMessage *message);
    void nouvellesValeurs();
    void envoiTrame(sigFoxMessage message);
    void afficherMessage(sigFoxMessage message);
  private:
    bool barreLed;
    bool demandeRetourMessage;
    bool electrovanneVille;
    char booleen[1];
    CArrosage arrosage;
    CChaleur fenetre;
    CFlotteur flotteurBas;
    CFlotteur flotteurHaut;
    CHumidite capteurHumiditeUn;
    CHumidite capteurHumiditeDeux;
    CHumidite capteurHumiditeTrois;
    CTemperature capteurTemperatureUn;
    CTemperature capteurTemperatureDeux;
    CLuminosite capteurLuminosite;
};