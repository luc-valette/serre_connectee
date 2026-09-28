#include <ArduinoLowPower.h>
#include <SigFox.h>
#include <DallasTemperature.h>

#include "classeCapteur.h"
#include "classeFlotteur.h"
#include "classeHumidite.h"
#include "classeLuminosite.h"
#include "classeTemperature.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeSigFox.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser SigFox
// Nom des composants utilises:/
// Historique du fichier:modifié le 07/03/23
/*************************************************/

typedef struct __attribute__ ((packed)) sigFoxMessage{
  uint8_t hum;
  int16_t temp;
  int32_t lum;
  uint8_t flot;
  bool vanne;
  bool pom;
}sigFoxMessage;

class classeSigFox{
  public:
    classeSigFox();
    sigFoxMessage newMessage(sigFoxMessage message);
    void newValeurs();
    int envoiTrame(sigFoxMessage message);
    void getDonnees();
  private:
    classeFlotteur flotteur;
    classeHumidite humidite;
    classeLuminosite luminosite;
    classeTemperature temperature;
};