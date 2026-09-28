#include <DallasTemperature.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <DFRobot_B_LUX_V30B.h>

#include "CCapteur.h" 

class CCapteurLuminosite : public CCapteur
{
public :
  CCapteurLuminosite();
  uint32_t GetLuminosite();
  void Change();
  uint32_t Luminosite();
private : 
  uint32_t luminosite;
};
