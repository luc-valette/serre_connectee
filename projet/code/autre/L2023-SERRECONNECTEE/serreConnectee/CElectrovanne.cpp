#include "CElectrovanne.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CElectrovanne.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CElectrovanne
// Nom des composants utilises:/
// Historique du fichier:modifié le31/05/2023
/*************************************************/

// Nom : CElectrovanne
// Rôle : constructeur de l'objet de type CElectrovanne, initialise l'état de l'électrovanne sur false, c'est-à-dire l'état fermé
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CElectrovanne::CElectrovanne(){
  this->etatElectrovanne=false;
}

// Nom : valeurElectrovanne
// Rôle : Retourne l'état de marche de l'électrovanne (si elle est ouverte, avec true, ou si elle est éteinte, avec false)
// Paramètres d'entrée : /
// Paramètres de sortie : etatElectrovanne
// Paramètres d'E/S : /
// Valeur de retour : /
bool CElectrovanne::valeurElectrovanne(){
  return this->etatElectrovanne;
}

// Nom : changerValeurActionneur
// Rôle : Change l'état de marche de l'électrovanne, true correspond à l'état marche, false correspond à l'état arrêt
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CElectrovanne::changerValeurActionneur(){
  if (this->etatElectrovanne){
    this->etatElectrovanne=false;
  }
  else{
    this->etatElectrovanne=true;
  }
}