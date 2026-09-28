#include "classeFlotteur.h"
//Pin A5 et A6 utilisés
//Méthode modiferValeur à modifier

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeFlotteur.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser les flotteurs.
// Nom des composants utilises:Vertical float level switch sensor (34764 sur gotronic)
// Historique du fichier:modifié le 14/02/23
/*************************************************/

// Nom : classeFlotteur
// Rôle : Constructeur de la classe classeFlotteur
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
classeFlotteur::classeFlotteur(){
  this->flotteur=modifierValeur();
}

// Nom : returnFlotteur
// Rôle : retourne la valeur courante du flotteur
// Paramètres d'entrée : /
// Paramètres de sortie : valeur du flotteur
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t classeFlotteur::returnFlotteur(){
  return this->flotteur;
}

// Nom : changerValeurCapteur
// Rôle : Permet de changer la valeur du flotteur dans l'objet représentant le flotteur en appellant la méthode modifierValeur et en mettant la valeur de retour dans l'objet flotteur
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void classeFlotteur::changerValeurCapteur(){
  this->modifierValeur();
}

// Nom : Flotteur
// Rôle : Permet de mettre à jour la valeur du flotteur
// Paramètres d'entrée : /
// Paramètres de sortie : Nouvelle valeur du flotteur avec val_flotteur
// Paramètres d'E/S : /
// Valeur de retour : /
uint8_t classeFlotteur::modifierValeur(){
  int flotteurBas=A4;
  int flotteurHaut=A5;
  float valeurFlotteurBas=analogRead(flotteurBas);
  float valeurFlotteurHaut=analogRead(flotteurHaut);
  return valeurFlotteurHaut-valeurFlotteurBas;
}