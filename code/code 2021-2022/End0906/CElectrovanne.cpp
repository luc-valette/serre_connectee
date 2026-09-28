#include "CElectrovanne.h"
#include "CCapteurHumidite.h"

#pragma once

CElectrovanne::CElectrovanne()
{
  this-> electrovanne =   Electrovanne();
}

int8_t CElectrovanne::GetElectrovanne()
{
  return electrovanne;
}

void CElectrovanne::Change()
{
  this-> electrovanne = Electrovanne();
}

int8_t CElectrovanne::Electrovanne() {
  
}
