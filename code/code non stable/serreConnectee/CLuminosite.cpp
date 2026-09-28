#include "CLuminosite.h"

CLuminosite::CLuminosite(int pin){
  this->pinLuminosite=pin;
  pinMode(this->pinLuminosite,INPUT);
}

uint32_t CLuminosite::valeurLuminosite(){
  return this->luminosite;
}

void CLuminosite::changerValeurCapteur(){
  this->luminosite=this->lireCapteur();
}

uint32_t CLuminosite::lireCapteur(){
  DFRobot_B_LUX_V30B myLux(this->pinLuminosite);
  myLux.begin();
  delay(1000);
  uint32_t lux=(int)myLux.lightStrengthLux();
  return lux;
}

int CLuminosite::valeurPinLuminosite(){
  return this->pinLuminosite;
}