#include "CCapteur.h"
#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 3

extern OneWire oneWire;

class CTemperature : public CCapteur{
  public:
    CTemperature(int pin, int typeCapteur);
    uint8_t valeurTemperature();
    void changerValeurCapteur();
    uint8_t lireCapteurUn();
    uint8_t lireCapteurDeux();
    int valeurPinTemperature();

  private:
    uint8_t temperature;
    int pinTemperature;
    int type;
};