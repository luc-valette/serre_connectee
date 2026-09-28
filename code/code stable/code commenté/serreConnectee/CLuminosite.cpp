#include "CLuminosite.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:
// Version:1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc Valette
// Date de création:2022
// Rôle du fichier:
// Nom des composants utilisés:/
// Historique du fichier:modifié par Luc le 31/05/2023
/*************************************************/

//pin utilisés : 11, 12, 13, 5V, gnd

// Nom : CLuminosite
// Rôle : constructeur de l'objet de type CLuminosite, la méthode utilise la méthode changerValeurCapteur() afin d'avoir le niveau de luminosité au moment de la création de l'objet
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CLuminosite::CLuminosite(int pin){
  this->pinLuminosite=pin;
  pinMode(this->pinLuminosite,INPUT);
}

// Nom : valeurLuminosite
// Rôle : retourne la valeur actuelle de la luminosité
// Paramètres d'entrée : /
// Paramètres de sortie : luminosite
// Paramètres d'E/S : /
// Valeur de retour : /
uint32_t CLuminosite::valeurLuminosite(){
  return this->luminosite;
}

// Nom : changerValeurCapteur
// Rôle : appelle la fonction qui permet de recupérer le niveau de luminosité et le place dans l'attribut luminosite
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CLuminosite::changerValeurCapteur(){
  this->luminosite=this->lireCapteur();
}

// Nom : lireCapteur
// Rôle : récupère la valeur de la luminosité pour calculer le niveau de luminosité et le renvoyer
// Paramètres d'entrée : /
// Paramètres de sortie : lux
// Paramètres d'E/S : /
// Valeur de retour : /
uint32_t CLuminosite::lireCapteur(){
  DFRobot_B_LUX_V30B myLux(this->pinLuminosite);
  myLux.begin();
  uint32_t lux=(int)myLux.lightStrengthLux();
  delay(1000); //J'ai eu parfois des problèmes lorsque je ne mettais pas cette ligne
  lux=(int)myLux.lightStrengthLux(); //Récupérer deux fois permet d'être sûr de vider le buffer
  return lux;
}

// Nom : valeurPinLuminosite
// Rôle : retourne le pin utilisé par le capteur de luminosité
// Paramètres d'entrée : /
// Paramètres de sortie : pinLuminosite
// Paramètres d'E/S : /
// Valeur de retour : /
int CLuminosite::valeurPinLuminosite(){
  return this->pinLuminosite;
}