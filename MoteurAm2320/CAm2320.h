#include "CCapteur.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

class CAm2320 : public CCapteur{
  public:
    CAm2320();
    void changerValeurCapteur();
    uint8_t valeurTemperature();
  private:
    uint8_t temperature;
    Adafruit_AM2320 capteur;
};