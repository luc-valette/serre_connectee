#pragma once
#include <ArduinoLowPower.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeCapteur.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet d'avoir une classe de capteur type
// Nom des composants utilises:/
// Historique du fichier:modifié le 14/02/23
/*************************************************/

class classeCapteur{
  public:
    virtual void changerValeurCapteur()=0;
  private:
};