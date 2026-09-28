#pragma once //Commande qui spécifie au compilateur d'inclure une seul fois ce fichier, même si on l'appelle plusieurs fois

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CActionneur.h
// Version:1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc Valette
// Date de création:2022
// Rôle du fichier:Crée une classe virtuelle, nommée CActionneur, qui inclue une fonction virtuelle qui sera utilisée dans les classes filles de cette classe
// Nom des composants utilisés:/
// Historique du fichier:modifié par Luc le 31/05/2023
/*************************************************/

class CActionneur {
  public:
    virtual void changerValeurActionneur()=0;
  private:
};