#include "CChaleur.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CChaleur.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CChaleur
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

// Nom : CChaleur
// Rôle : constructeur de l'objet de type CChaleur, initialise l'objet pompe ainsi que les données à utiliser pour ouvrir et fermer la fenêtre
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CChaleur::CChaleur(int pinUn, int pinDeux, int seuilFaible, int seuilFort){
  this->pinUnMoteur=pinUn;
  this->pinDeuxMoteur=pinDeux;
  this->seuilMax=seuilFort;
  this->seuilMin=seuilFaible;

  pinMode(this->pinUnMoteur,OUTPUT);
  pinMode(this->pinDeuxMoteur,OUTPUT);
}

// Nom : ouvrirSiBesoin
// Rôle : Vérifie la température reçue par le capteur et allume le moteur afin d'ouvrir ou fermer la fenêtre
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CChaleur::ouvrirSiBesoin(){
  if (this->temperatureActuelle>this->seuilMax){
    if (!(this->moteur.valeurMoteur())){
      this->moteur.changerValeurActionneur();
      digitalWrite(this->pinUnMoteur,LOW); 
      digitalWrite(this->pinDeuxMoteur,HIGH);
      delay(30*1000);
      digitalWrite(this->pinUnMoteur,HIGH);
      digitalWrite(this->pinDeuxMoteur,HIGH);
    }
  }

  else if (this->temperatureActuelle<this->seuilMin){
    if (this->moteur.valeurMoteur()){
      this->moteur.changerValeurActionneur();
      digitalWrite(this->pinUnMoteur,HIGH); 
      digitalWrite(this->pinDeuxMoteur,LOW);
      delay(30*1000);
      digitalWrite(this->pinUnMoteur,HIGH);
      digitalWrite(this->pinDeuxMoteur,HIGH);
    }
  }
}

// Nom : changerValeurTemperature
// Rôle : Attribue à humiditeActuelle la valeur de l'humidité reçue par le capteur
// Paramètres d'entrée : valeurTemperature
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CChaleur::changerValeurTemperature(int valeurTemperature){
  this->temperatureActuelle=valeurTemperature;
}

// Nom : getTemperatureActuelle
// Rôle : retourne la valeur de la température qui est utilisée sur le moment
// Paramètres d'entrée : /
// Paramètres de sortie : temperatureActuelle
// Paramètres d'E/S : /
// Valeur de retour : /
int CChaleur::valeurTemperatureActuelle(){
  return this->temperatureActuelle;
}

// Nom : valeurSeuilMax
// Rôle : retourne la valeur du seuil en dessus du quel la fenêtre se ferme
// Paramètres d'entrée : /
// Paramètres de sortie : seuilMax
// Paramètres d'E/S : /
// Valeur de retour : /
int CChaleur::valeurSeuilMax(){
  return this->seuilMax;
}

// Nom : valeurSeuilMin
// Rôle : retourne la valeur du seuil en dessous du quel la fenêtre s'ouvre
// Paramètres d'entrée : /
// Paramètres de sortie : seuilMin
// Paramètres d'E/S : /
// Valeur de retour : /
int CChaleur::valeurSeuilMin(){
  return this->seuilMin;
}

// Nom : valeurFenetre
// Rôle : retourne l'état de la fenêtre, true si elle est allumée, false si elle est éteinte
// Paramètres d'entrée : /
// Paramètres de sortie : etatMoteur
// Paramètres d'E/S : /
// Valeur de retour : /
bool CChaleur::valeurFenetre(){
  return this->moteur.valeurMoteur();
}

// Nom : valeurPinUnFenetre
// Rôle : Retourne le premier pin utilisé par le moteur
// Paramètres d'entrée : /
// Paramètres de sortie : pinUnMoteur
// Paramètres d'E/S : /
// Valeur de retour : /
int CChaleur::valeurPinUnFenetre(){
  return this->pinUnMoteur;
}

// Nom : valeurPinDeuxFenetre
// Rôle : Retourne le second pin utilisé par le moteur
// Paramètres d'entrée : /
// Paramètres de sortie : pinDeuxMoteur
// Paramètres d'E/S : /
// Valeur de retour : /
int CChaleur::valeurPinDeuxFenetre(){
  return this->pinDeuxMoteur;
}