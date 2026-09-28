#include <DallasTemperature.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 3

#include "CActionneur.h" 

extern OneWire oneWire;

class CElectrovanne : public CActionneur
{
public :
  CElectrovanne();
  int8_t GetElectrovanne();
  void Change();
  int8_t Electrovanne();
  float getElec();
private : 
  int8_t electrovanne;
};
