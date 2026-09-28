#include <SigFox.h>
#include <Arduino.h>

#include "CFlotteur.h"
#include "CHumidite.h"
#include "CLuminosite.h"
#include "CTemperature.h"
#include "CArrosage.h"
#include "CChaleur.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CSigFox.h
// Version:1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc Valette
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CSigFox
// Nom des composants utilisés:MKRFOX1200
// Historique du fichier:modifié par Luc le 31/05/2023
/*************************************************/

typedef struct __attribute__ ((packed)) sigFoxMessage{
  char etat[1];
  uint8_t humiditeExterieure;
  uint8_t humiditeInterieure;
  uint8_t humiditeSol;
  uint8_t temperatureExterieure;
  uint8_t temperatureInterieure;
  uint32_t luminosite;
}sigFoxMessage;

class CSigFox{
  public:
    CSigFox();
    void nouveauMessage(sigFoxMessage *message);
    void nouvellesValeurs();
    void envoiTrame(sigFoxMessage message);
    void afficherMessage(sigFoxMessage message);
  private:
    bool barreLed;
    bool demandeRetourMessage;
    bool electrovanneVille;
    char booleen[1];
    CArrosage arrosage;
    CChaleur fenetre;
    CFlotteur flotteurBas;
    CFlotteur flotteurHaut;
    CHumidite capteurHumiditeUn;
    CHumidite capteurHumiditeDeux;
    CHumidite capteurHumiditeTrois;
    CTemperature capteurTemperatureUn;
    CTemperature capteurTemperatureDeux;
    CLuminosite capteurLuminosite;
};