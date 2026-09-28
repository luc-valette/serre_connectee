#include "CCapteurHumidite.h" 
 

CCapteurHumidite::CCapteurHumidite()
{
  this-> humidity = Humidity();
}

uint8_t CCapteurHumidite::GetHumidity()
{
  return humidity;
}

uint8_t CCapteurHumidite::Humidity(){
    int soilMoistureValue = 0;
    uint8_t WaterVal = 0;
    soilMoistureValue = analogRead(A1);  
    WaterVal = 100 - soilMoistureValue / 9;   
    return WaterVal;

}


void CCapteurHumidite::Change()
{
  this->humidity = Humidity();
}
