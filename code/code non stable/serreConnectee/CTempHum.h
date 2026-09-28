#pragma once

#include <Adafruit_Sensor.h>
#include <Adafruit_AM2320.h>

class CTempHum{
  public:
    CTempHum();
    float getTemp();
    float getHum();
  private:
    float temp;
    float hum;
    Adafruit_AM2320 capteur;
};
