#include "CTempHum.h"

CTempHum::CTempHum(){
  this->capteur = Adafruit_AM2320();
  this->capteur.begin();
}

float CTempHum::getTemp(){
  this->temp=this->capteur.readTemperature();
  return this->temp;
}
float CTempHum::getHum(){
  this->hum=this->capteur.readHumidity();
  return this->hum;
}
