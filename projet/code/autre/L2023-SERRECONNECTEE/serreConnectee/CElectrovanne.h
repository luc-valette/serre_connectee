#include "CActionneur.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CElectrovanne.h
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Eric JALAO
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CElectrovanne
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/

class CElectrovanne:public CActionneur{
  public:
    CElectrovanne();
    bool valeurElectrovanne();
    void changerValeurActionneur();
  private:
    bool etatElectrovanne;
};