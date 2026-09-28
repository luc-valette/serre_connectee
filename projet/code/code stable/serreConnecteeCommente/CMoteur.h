#include "CActionneur.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:Cmoteur.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthodes de la classe CMoteur
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

class CMoteur : public CActionneur{
  public:
    CMoteur();
    bool valeurMoteur();
    void changerValeurActionneur();
  private:
    bool etatMoteur;
};