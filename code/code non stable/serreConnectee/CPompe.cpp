#include "CPompe.h"

CPompe::CPompe(){
  this->etatPompe=false;
}

bool CPompe::valeurPompe(){
  return this->etatPompe;
}

void CPompe::changerValeurActionneur(){
  if (this->etatPompe){
    this->etatPompe=false;
  }
  else{
    this->etatPompe=true;
  }
}