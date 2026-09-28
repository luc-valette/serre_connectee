#include <DallasTemperature.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>

#include "CCapteur.h" 




class CCapteurHumidite : public CCapteur
{
public :
	CCapteurHumidite();
  uint8_t Humidity();
	uint8_t GetHumidity();
  void Change();
  
private :
	uint8_t humidity;

};
