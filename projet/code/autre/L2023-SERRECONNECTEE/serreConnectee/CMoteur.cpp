#include "CMoteur.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CMoteur.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CMoteur
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

// Nom : CMoteur
// Rôle : constructeur de l'objet de type CMoteur, initialise l'état du moteur sur false, c'est-à-dire la fenêtre est fermée
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CMoteur::CMoteur(){
  this->etatMoteur=false;
}

// Nom : valeurMoteur
// Rôle : Retourne l'état de marche du moteur (si il est en marche, avec true, ou s'il est à l'arrêt, avec false)
// Paramètres d'entrée : /
// Paramètres de sortie : etatMoteur
// Paramètres d'E/S : /
// Valeur de retour : /
bool CMoteur::valeurMoteur(){
  return this->etatMoteur;
}

// Nom : changerValeurActionneur
// Rôle : Change l'état d'ouverture de la fenêtre, true correspond à l'état ouvert, false correspond à l'état fermé
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CMoteur::changerValeurActionneur(){
  if (this->etatMoteur){
    this->etatMoteur=false;
  }
  else{
    this->etatMoteur=true;
  }
}
