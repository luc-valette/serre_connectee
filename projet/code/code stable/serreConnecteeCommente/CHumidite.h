#include "CCapteur.h"
#include <Arduino.h>

/*************************************************/
// Nom du projet: Serre connectée
// Nom du fichier: CHumidite.h
// Version: 1.0
// Nom du programmeur: OpenAI
// Date de création: 2023
// Rôle du fichier: Ce fichier permet de répertorier tous les attributs et méthodes de la classe CHumidite, qui est une classe fille de la classe CCapteur.
// Nom des composants utilisés: SEN0390, AM2320, moisture sensor grove
// Historique du fichier: Aucune modification
/*************************************************/

// Pins utilisés : A1, A2, 11, 12, 5V, GND

class CHumidite : public CCapteur{
  public:
    CHumidite(int pin, int typeCapteur);
    uint8_t valeurHumidite();
    void changerValeurCapteur();
    uint8_t lireCapteurUn();
    uint8_t lireCapteurDeux();
    uint8_t lireCapteurTrois();
    int valeurPinHumidite();
  private:
    uint8_t humidite;
    int pinHumidite;
    int type;
};