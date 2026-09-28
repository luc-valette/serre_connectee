
#include <DallasTemperature.h>
#include <SigFox.h>
#include <ArduinoLowPower.h>

#include "CCapteurHumidite.h"
#include "CCapteurTemperature.h"
#include "CCapteurLuminosite.h"
#include "CCapteurFlotteur.h"

typedef struct __attribute__ ((packed)) sigfox_message
{
  uint8_t Hum;
  int16_t Temp;
  uint32_t Lum;
  uint8_t Flo;
  bool Ele;
  bool Mot;
  
}sigfox_message;

class TransmissionSigfox
{
public:
	TransmissionSigfox();

  sigfox_message TrameSigfox(sigfox_message message);

  int EnvoieTrameSigfox(sigfox_message message);

  void RefreshTrameSigfox();


private :

	CCapteurHumidite H;
  CCapteurTemperature T;
  CCapteurLuminosite L;
  CCapteurFlotteur F;
	
};
