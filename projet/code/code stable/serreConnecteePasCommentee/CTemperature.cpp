#include "CTemperature.h"

CTemperature::CTemperature(int pin, int typeCapteur){
  this->type = typeCapteur;
  if (this->type == 1){
    this->pinTemperature = -1;
    this->temperature=this->lireCapteurUn();
  }
  else{
    this->pinTemperature = pin;
    pinMode(this->pinTemperature, INPUT);
    this->temperature=this->lireCapteurDeux();
  }
}

uint8_t CTemperature::valeurTemperature(){
  return this->temperature;
}

void CTemperature::changerValeurCapteur(){
  if (this->type == 1){
    this->temperature = this->lireCapteurUn();
  }
  else{
    this->temperature = this->lireCapteurDeux();
  }
}

uint8_t CTemperature::lireCapteurUn(){
  return (35+20)*2;
}

uint8_t CTemperature::lireCapteurDeux() {
  OneWire ds(this->pinTemperature);
  byte data[9];
  byte addr[8];

  if (!ds.search(addr)) {
    ds.reset_search();
    return -1000;
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if (addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);

  for (int i = 0; i < 9; i++) {
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB);
  tempRead /= 16;
  tempRead += 20;
  tempRead *= 2;

  int TemperatureSum=(int)tempRead;

  return (uint8_t)TemperatureSum;
}

int CTemperature::valeurPinTemperature() {
  return this->pinTemperature;
}