#include "CArrosage.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CArrosage.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CArrosage
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

//pin utilisés : 0, 5V, gnd

// Nom : CArrosage
// Rôle : constructeur de l'objet de type CArrosage, initialise les objets pompe et electrovanne ainsi que les données à utiliser pour ouvrir et fermer ces deux actionneurs
// Paramètres d'entrée : pin, seuilFaible, seuilFort
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CArrosage::CArrosage(int pin, int seuilFaible, int seuilFort){
  this->pinArrosage=pin;
  this->seuilBas=seuilFaible;
  this->seuilHaut=seuilFort;
  
  pinMode(this->pinArrosage,OUTPUT);
}

// Nom : arroserSiBesoin
// Rôle : Vérifie le pourcentage d'humidité reçu du capteur et ouvre ou ferme l'électrovanne et la pompe d'après ce pourcentage
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CArrosage::arroserSiBesoin(){
  if (this->humiditeActuelle<this->seuilBas){
    if (!(this->electrovanne.valeurElectrovanne())){
      this->electrovanne.changerValeurActionneur();
      this->pompe.changerValeurActionneur();
      digitalWrite(this->pinArrosage,HIGH);
    }
  }

  else if (this->humiditeActuelle>this->seuilHaut){
    if (this->electrovanne.valeurElectrovanne()){
      this->electrovanne.changerValeurActionneur();
      this->pompe.changerValeurActionneur();
      digitalWrite(this->pinArrosage, LOW);
    }
  }
}

// Nom : changerValeurHumidite
// Rôle : Attribue à humiditeActuelle la valeur de l'humidité reçue par le capteur
// Paramètres d'entrée : valeurHumidite
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CArrosage::changerValeurHumidite(int valeurHumidite){
  this->humiditeActuelle=valeurHumidite;
}

// Nom : valeurElectrovanne
// Rôle : retourne l'état de l'électrovanne, true si elle est allumée, false si elle est éteinte
// Paramètres d'entrée : /
// Paramètres de sortie : etatElectrovanne
// Paramètres d'E/S : /
// Valeur de retour : /
bool CArrosage::valeurElectrovanne(){
  return this->electrovanne.valeurElectrovanne();
}

// Nom : valeurPompe
// Rôle : retourne l'état de la pompe, true si elle est allumée, false si elle est éteinte
// Paramètres d'entrée : /
// Paramètres de sortie : etatPompe
// Paramètres d'E/S : /
// Valeur de retour : /
bool CArrosage::valeurPompe(){
  return this->pompe.valeurPompe();
}

// Nom : valeurSeuilBas
// Rôle : retourne la valeur du seuil en dessus du quel l'arrosage s'allume
// Paramètres d'entrée : /
// Paramètres de sortie : humiditeActuelle
// Paramètres d'E/S : /
// Valeur de retour : /
int CArrosage::valeurSeuilBas(){
  return this->seuilBas;
}

// Nom : valeurSeuilHaut
// Rôle : retourne la valeur du seuil en dessus du quel l'arrosage s'éteint
// Paramètres d'entrée : /
// Paramètres de sortie : seuilHaut
// Paramètres d'E/S : /
// Valeur de retour : /
int CArrosage::valeurSeuilHaut(){
  return this->seuilHaut;
}

// Nom : valeurHumiditeActuelle
// Rôle : retourne l'humidité utilisé par l'arrosage au moment de la demande
// Paramètres d'entrée : /
// Paramètres de sortie : humiditeActuelle
// Paramètres d'E/S : /
// Valeur de retour : /
int CArrosage::valeurHumiditeActuelle(){
  return this->humiditeActuelle;
}

// Nom : valeurPin
// Rôle : Retourne le pin utilisé par l'arrosage
// Paramètres d'entrée : /
// Paramètres de sortie : pinArrosage
// Paramètres d'E/S : /
// Valeur de retour : /
int CArrosage::valeurPin(){
  return this->pinArrosage;
}