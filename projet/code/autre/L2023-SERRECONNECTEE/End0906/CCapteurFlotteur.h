#include <DallasTemperature.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <OneWire.h>

#include "CCapteur.h" 

class CCapteurFlotteur : public CCapteur
{
public :
	CCapteurFlotteur();
  uint8_t GetFlotteur();
  void Change();
  uint8_t Flotteur();
  float getFlot();
private : 
  uint8_t flotteur;
};
