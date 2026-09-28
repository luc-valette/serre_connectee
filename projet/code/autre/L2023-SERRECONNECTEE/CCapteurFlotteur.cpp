#include "CCapteurFlotteur.h" 

CCapteurFlotteur::CCapteurFlotteur()
{
  this-> flotteur = Flotteur();
}

uint8_t CCapteurFlotteur::GetFlotteur()
{
  return flotteur;
}

uint8_t CCapteurFlotteur::Flotteur(){
    int flotteur_bas = A5;
    int flotteur_haut = A6;
    bool val_flotteur_bas = analogRead(flotteur_bas);
    bool val_flotteur_haut = analogRead(flotteur_haut);
    int val_flotteur = val_flotteur_bas + val_flotteur_haut;

    return val_flotteur_bas;
}


void CCapteurFlotteur::Change()
{
  this->flotteur = Flotteur();
}
