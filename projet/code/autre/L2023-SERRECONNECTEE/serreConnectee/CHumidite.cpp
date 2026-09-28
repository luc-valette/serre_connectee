#include "CHumidite.h"

Adafruit_AM2320 AM2320 = Adafruit_AM2320();

/*************************************************/
// Nom du projet: Serre connectée
// Nom du fichier: CHumidite.cpp
// Version: 1.1
// Nom du programmeur: Groupe serre connectée 2021/2022, Luc Valette
// Date de création: 2022
// Rôle du fichier: Ce fichier contient les définitions des méthodes de la classe CHumidite.
// Nom des composants utilisés: SEN0390, AM2320, moisture sensor grove
// Historique du fichier: modifié par Luc le 31/05/2023
/*************************************************/

// Pins utilisés : A1, A2, 11, 12, 5V, GND

// Nom : CHumidite
// Rôle : constructeur de l'objet de type CHumidite, la méthode utilise la méthode changerValeurCapteur() afin d'avoir le pourcentage d'humidite au moment de la création de l'objet
// Paramètres d'entrée : pin, typeCapteur
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CHumidite::CHumidite(int pin, int typeCapteur) {
  this->type = typeCapteur;
  if (this->type == 3) {
    this->pinHumidite = -1;
  } else {
    this->pinHumidite = pin;
    pinMode(this->pinHumidite, INPUT);
  }
  this->changerValeurCapteur();
}

// Nom : valeurHumidite
// Rôle : retourne la valeur actuelle reçue par le capteur d'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : humidite
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CHumidite::valeurHumidite() {
  return this->humidite;
}

// Nom : changerValeurCapteur
// Rôle : appelle la fonction qui permet de récupérer le niveau d'humidité et le place dans l'attribut humidite, elle regarde d'abord quel capteur est demandé puis appelle la fonction adéquate
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CHumidite::changerValeurCapteur() {
  if (this->type == 1) {
    this->humidite = this->lireCapteurUn();
  } else if (this->type == 2) {
    this->humidite = this->lireCapteurDeux();
  } else {
    this->humidite = this->lireCapteurTrois();
  }
}

// Nom : lireCapteurUn
// Rôle : récupère la valeur de l'humidité pour calculer le niveau d'humidité et le renvoyer, cette méthode est utilisée pour le premier capteur d'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : valeurHumdite
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CHumidite::lireCapteurUn() {
  uint8_t valeurHumidite = 100 - analogRead(this->pinHumidite) / 9.0;
  return valeurHumidite;
}

// Nom : lireCapteurDeux
// Rôle : récupère la valeur de l'humidité pour calculer le niveau d'humidité et le renvoyer, cette méthode est utilisée pour le deuxième capteur d'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : valeurHumdite
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CHumidite::lireCapteurDeux() {
  uint8_t valeurHumidite = analogRead(this->pinHumidite) / 10.23;
  return valeurHumidite;
}

// Nom : lireCapteurTrois
// Rôle : récupère la valeur de l'humidité pour calculer le niveau d'humidité et le renvoyer, cette méthode est utilisée pour le troisième capteur d'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : valeurHumdite
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t CHumidite::lireCapteurTrois() {
  AM2320.begin();
  uint8_t humidite = (int)AM2320.readHumidity();
  return humidite;
}

// Nom : valeurPinHumidite
// Rôle : retourne le pin utilisé par le capteur d'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : pinHumidite
// Paramètres d'E/S : /
// Valeur de retour : /
int CHumidite::valeurPinHumidite() {
  return this->pinHumidite;
}
