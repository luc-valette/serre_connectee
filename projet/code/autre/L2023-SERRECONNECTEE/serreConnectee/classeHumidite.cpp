#include "classeHumidite.h"
//Pin A1 utilisé

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeHumidite.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser le capteur d'humidité.
// Nom des composants utilises:/
// Historique du fichier:modifié le 14/02/23
/*************************************************/

// Nom : classeHumidite
// Rôle : Constructeur de la classe classeHumidite
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
classeHumidite::classeHumidite(){
  this->humidite=modifierValeur();
}

// Nom : returnHumidite
// Rôle : retourne la valeur de l'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : valeur de l'humidité
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t classeHumidite::returnHumidite(){
  return this->humidite;
}

// Nom : changerValeurCapteur
// Rôle : Place la valeur de retour de la méthode modiferValeur dans la viriable humidite
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void classeHumidite::changerValeurCapteur(){
  this->humidite=modifierValeur();
}

// Nom : modifierValeur
// Rôle : Récupère et renvoie la valeur du capteur d'humidité
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : Retourne la valeur du capteur d'humidité
uint8_t classeHumidite::modifierValeur(){
  int soilMoistureValue = 0;
  uint8_t WaterVal = 0;
  soilMoistureValue = analogRead(A1);
  WaterVal = 100 - soilMoistureValue / 9;
  return WaterVal;
}