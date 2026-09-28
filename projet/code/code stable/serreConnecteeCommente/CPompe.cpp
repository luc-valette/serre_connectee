#include "CPompe.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CPompe.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CPompe
// Nom des composants utilises:/
// Historique du fichier:modifié le 04/04/2023
/*************************************************/

// Nom : CPompe
// Rôle : constructeur de l'objet de type CPompe, initialise l'état de la pompe à false, c'est-à-dire sur l'état fermé
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CPompe::CPompe(){
  this->etatPompe=false;
}

// Nom : valeurPompe
// Rôle : Retourne l'état de marche de la pompe (si elle est ouverte, avec true, ou si elle est éteinte, avec false)
// Paramètres d'entrée : /
// Paramètres de sortie : etatPompe
// Paramètres d'E/S : /
// Valeur de retour : /
bool CPompe::valeurPompe(){
  return this->etatPompe;
}

// Nom : changerValeurActionneur
// Rôle : Change l'état de marche de la pompe, true correspond à l'état marche, false correspond à l'état arrêt
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CPompe::changerValeurActionneur(){
  if (this->etatPompe){
    this->etatPompe=false;
  }
  else{
    this->etatPompe=true;
  }
}