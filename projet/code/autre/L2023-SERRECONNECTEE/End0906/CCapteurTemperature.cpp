#include "CCapteurTemperature.h" 
OneWire oneWire(ONE_WIRE_BUS);
OneWire ds(A3);


CCapteurTemperature::CCapteurTemperature()
{
  this-> temperature = Temperature();
}


int16_t CCapteurTemperature::GetTemperature()
{
  return temperature;
}

void CCapteurTemperature::Change()
{
  this-> temperature = Temperature();
}

int16_t CCapteurTemperature::Temperature() {
  int16_t temp;
  float temperature = getTemp();
  delay(1000);
  temperature = getTemp();
  temperature = temperature * 100;
  temp = (int16_t) temperature;
  return temp;


}



float CCapteurTemperature::getTemp(){
  //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad


  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;

}
