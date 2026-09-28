#include "classeSigFox.h"
#include <SigFox.h>

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:classeSigFox.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de faire les méthodes de la classe permettant d'utiliser SigFox
// Nom des composants utilises:/
// Historique du fichier:modifié le 07/03/23
/*************************************************/

// Nom : classeSigFox
// Rôle : Constructeur de la classe classeSigFox
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
classeSigFox::classeSigFox(){}

// Nom : newMessage
// Rôle : Cette méthode mets à jour le message pour SigFox
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
sigFoxMessage classeSigFox::newMessage(sigFoxMessage message){
  message.hum=this->humidite.returnHumidite();
  message.temp=this->temperature.returnTemperature();
  message.lum=this->luminosite.returnLuminosite();
  message.flot=this->flotteur.returnFlotteur();

  return message;
}

// Nom : trameSigfox
// Rôle : Cette méthode mets à jour les valeurs des capteurs
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void classeSigFox::newValeurs(){
  this->flotteur.changerValeurCapteur();
  this->humidite.changerValeurCapteur();
  this->luminosite.changerValeurCapteur();
  this->temperature.changerValeurCapteur();
}

// Nom : envoiTrame
// Rôle : Cette méthode permet d'envoyer le message sur le réseau Sigfox, la valeur de retour est l'accusé de reception du message
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
int classeSigFox::envoiTrame(sigFoxMessage message){
  Serial.print("Méthode envoi lancé\n");
  SigFox.beginPacket();
  Serial.print("Connexion effectuée\n");
  SigFox.write(message);
  Serial.print("Message passé\n");
  int rep=SigFox.endPacket();
  Serial.print("Connexion fermée\n");

  return rep;
}

// Nom : envoiTrame
// Rôle : Cette méthode permet d'envoyer le message sur le réseau Sigfox, la valeur de retour est l'accusé de reception du message
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void classeSigFox::getDonnees(){
  Serial.print("Valeurs :\n");
  Serial.print("Humidité : ");
  Serial.println(this->humidite.returnHumidite());
  Serial.print("Température : ");
  Serial.println(this->temperature.returnTemperature());
  Serial.print("Luminosité : ");
  Serial.println(this->luminosite.returnLuminosite());
  Serial.print("Flotteur : ");
  Serial.println(this->flotteur.returnFlotteur());
}