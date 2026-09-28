#include "CFlotteur.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CFlotteur.cpp
// Version:1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc Valette
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CFlotteur, cette classe est une classe fille de la classe CCapteur
// Nom des composants utilisés:C7249
// Historique du fichier:modifié par Luc le 31/05/2023
/*************************************************/

//pin utilisés : 3, 4, 5V

// Nom : CFlotteur
// Rôle : constructeur de l'objet de type CFlotteur, la méthode utilise la méthode changerValeurCapteur() afin d'avoir le niveau d'eau au moment de la création de l'objet
// Paramètres d'entrée : pin
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CFlotteur::CFlotteur(int pin){
  this->pinFlotteur=pin;
  pinMode(this->pinFlotteur,INPUT);
  this->changerValeurCapteur();
}

// Nom : valeurFlotteur
// Rôle : retourne la valeur actuelle du flotteur
// Paramètres d'entrée : /
// Paramètres de sortie : flotteur
// Paramètres d'E/S : /
// Valeur de retour : /
bool CFlotteur::valeurFlotteur(){
  return this->flotteur;
}

// Nom : changerValeurCapteur
// Rôle : appelle la fonction qui permet de recupérer le niveau d'eau et le place dans l'attributs flotteur 
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CFlotteur::changerValeurCapteur(){
  this->flotteur=this->lireCapteur();
}

// Nom : lireCapteur
// Rôle : Lit la valeur entrant sur le port du capteur et retourne un booléen selon cette valeur
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
bool CFlotteur::lireCapteur(){
  int valeur=digitalRead(this->pinFlotteur);
  if (valeur==0){
    return false;
  }
  else {
    return true;
  }
}

// Nom : getPinFlotteurBas
// Rôle : retourne le pin utilisé par le flotteur
// Paramètres d'entrée : /
// Paramètres de sortie : flotteurBas
// Paramètres d'E/S : /
// Valeur de retour : /
int CFlotteur::valeurPinFLotteur(){
  return this->pinFlotteur;
}