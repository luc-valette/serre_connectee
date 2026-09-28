#include "CElectrovanne.h"
CElectrovanne::CElectrovanne(){
  this->etatElectrovanne=false;
}
bool CElectrovanne::valeurElectrovanne(){
  return this->etatElectrovanne;
}
void CElectrovanne::changerValeurActionneur(){
  if (this->etatElectrovanne){
    this->etatElectrovanne=false;
  }
  else{
    this->etatElectrovanne=true;
  }
}