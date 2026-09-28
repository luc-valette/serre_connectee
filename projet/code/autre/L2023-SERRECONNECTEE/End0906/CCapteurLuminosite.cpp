#include "CCapteurLuminosite.h" 


CCapteurLuminosite::CCapteurLuminosite()
{
  this-> luminosite = Luminosite();
}

uint32_t CCapteurLuminosite::GetLuminosite()
{
  return luminosite;
}

void CCapteurLuminosite::Change()
{
  this-> luminosite = Luminosite();
}

uint32_t CCapteurLuminosite::Luminosite() {
  DFRobot_B_LUX_V30B myLux(13);
  uint32_t lux = 0;
  lux = (uint32_t)myLux.lightStrengthLux();
  return lux;

  
}
