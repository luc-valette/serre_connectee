#include "CMoteur.h"

CMoteur::CMoteur(){
  this->etatMoteur=false;
}

bool CMoteur::valeurMoteur(){
  return this->etatMoteur;
}

void CMoteur::changerValeurActionneur(){
  if (this->etatMoteur){
    this->etatMoteur=false;
  }
  else{
    this->etatMoteur=true;
  }
}