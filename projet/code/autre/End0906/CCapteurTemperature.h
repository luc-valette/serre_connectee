#include <DallasTemperature.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <OneWire.h>


#define ONE_WIRE_BUS 3

#include "CCapteur.h" 

extern OneWire oneWire;



class CCapteurTemperature : public CCapteur
{
public :
	CCapteurTemperature();
  int16_t GetTemperature();
  void Change();
  int16_t Temperature();
  float getTemp();
private : 
  int16_t temperature;
};
