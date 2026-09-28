#include "classeLuminosite.h"
//Pin 13 utilisé

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeLuminosite.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser le capteur de luminosité.
// Nom des composants utilises:/
// Historique du fichier:modifié le 14/02/23
/*************************************************/

// Nom : classeLuminosite
// Rôle : Constructeur de la classe classeLuminosite
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
classeLuminosite::classeLuminosite(){
  this->luminosite=modifierValeur();
}

// Nom : returnLuminosite
// Rôle : retourne la valeur de la luminosité
// Paramètres d'entrée : /
// Paramètres de sortie : valeur de la luminosité
// Paramètres d'E/S : /
// Valeur de retour : /
uint32_t classeLuminosite::returnLuminosite(){
  return this->luminosite;
}

// Nom : changerValeurCapteur
// Rôle : Place dans l'attribut luinosite une nouvelle valeur
// Paramètres d'entrée : /
// Paramètres de sortie : valeur de la luminosité
// Paramètres d'E/S : /
// Valeur de retour : /
void classeLuminosite::changerValeurCapteur(){
  this->luminosite=modifierValeur();
}

// Nom : modifierValeur
// Rôle : Récupère la valeur du capteur et la retourne
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : valeur de la lumière sur 8 bits
uint32_t classeLuminosite::modifierValeur(){
  DFRobot_B_LUX_V30B myLux(13);
  return (uint32_t)myLux.lightStrengthLux();
}