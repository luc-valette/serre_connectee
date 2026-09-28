#include "TransmissionSigfox.h"



TransmissionSigfox::TransmissionSigfox()
{
}

sigfox_message TransmissionSigfox::TrameSigfox(sigfox_message message)
{
	message.Hum = this->H.GetHumidity();
  message.Temp = this->T.GetTemperature();
  message.Lum = this->L.GetLuminosite();
  message.Flo = this->F.GetFlotteur();

  return message;
}

int TransmissionSigfox::EnvoieTrameSigfox(sigfox_message message)
{

   SigFox.beginPacket();
   SigFox.write(message);
   int ret = SigFox.endPacket();

   return ret;
  
}

void TransmissionSigfox::RefreshTrameSigfox()
{
  this->H.CCapteurHumidite::Change();
  this->T.CCapteurTemperature::Change();
  this->L.CCapteurLuminosite::Change();
  this->F.CCapteurFlotteur::Change();
}
