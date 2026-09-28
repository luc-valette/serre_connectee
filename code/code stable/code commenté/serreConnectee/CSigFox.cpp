#include "CSigFox.h"

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:CSigFox.cpp
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Ce fichier permet de répertorier tout les attributs et méthode de la classe CSigFox
// Nom des composants utilises:/
// Historique du fichier:modifié le 04/04/2023
/*************************************************/

// Nom : CSigFox
// Rôle : Constructeur de la classe CSigFox, initialise tout les objets que la classe utilisera par la suite
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
CSigFox::CSigFox():arrosage(0,20,80), fenetre(1,2,20,50), flotteurBas(3), flotteurHaut(4), capteurHumiditeUn(A1,1), capteurHumiditeDeux(0,2), capteurHumiditeTrois(A2,3), capteurTemperatureUn(0,1), capteurTemperatureDeux(A3,2), capteurLuminosite(13){
  this->barreLed=false;
  this->electrovanneVille=false;
  this->demandeRetourMessage=false;
}

// Nom : nouveauMessage
// Rôle : Met à jour le message à envoyer sur SigFox avec les nouvelles valeurs
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : message
// Valeur de retour : /
void CSigFox::nouveauMessage(sigFoxMessage *message){
  this->booleen[0]=false*128+this->demandeRetourMessage*64+this->flotteurHaut.valeurFlotteur()*32+this->flotteurBas.valeurFlotteur()*16+this->electrovanneVille*8+this->fenetre.valeurFenetre()*4+this->barreLed*2+this->arrosage.valeurElectrovanne()*1;
  message->etat[0]=booleen[0];
  message->humiditeExterieure=this->capteurHumiditeUn.valeurHumidite();
  message->humiditeInterieure=this->capteurHumiditeDeux.valeurHumidite();
  message->humiditeSol=this->capteurHumiditeTrois.valeurHumidite();
  message->temperatureInterieure=this->capteurTemperatureUn.valeurTemperature();
  message->temperatureExterieure=this->capteurTemperatureDeux.valeurTemperature();
  message->luminosite=this->capteurLuminosite.valeurLuminosite();
}

// Nom : nouvellesValeurs
// Rôle : Met à jour les valeurs des capteurs et actionneurs
// Paramètres d'entrée : /
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CSigFox::nouvellesValeurs(){
  this->flotteurBas.changerValeurCapteur();
  this->flotteurHaut.changerValeurCapteur();
  this->capteurHumiditeUn.changerValeurCapteur();
  this->capteurHumiditeDeux.changerValeurCapteur();
  this->capteurHumiditeTrois.changerValeurCapteur();
  this->capteurTemperatureUn.changerValeurCapteur();
  this->capteurTemperatureDeux.changerValeurCapteur();
  this->capteurLuminosite.changerValeurCapteur();
  this->fenetre.changerValeurTemperature(this->capteurTemperatureUn.valeurTemperature());
  this->fenetre.ouvrirSiBesoin(); 
  this->arrosage.changerValeurHumidite(this->capteurHumiditeTrois.valeurHumidite());
  this->arrosage.arroserSiBesoin();
}

// Nom : envoiTrame
// Rôle : Envoi le mesage sur le réseau SigFox
// Paramètres d'entrée : message
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CSigFox::envoiTrame(sigFoxMessage message){
  SigFox.beginPacket();
  SigFox.write(message);
  int ret = SigFox.endPacket();
}

// Nom : afficherMessage
// Rôle : Affiche sur le moniteur série toutes les informations du message à envoyer sur SigFox
// Paramètres d'entrée : message
// Paramètres de sortie : /
// Paramètres d'E/S : /
// Valeur de retour : /
void CSigFox::afficherMessage(sigFoxMessage message){
  //Décompose et affiche le premier octet avec des décalage de bits et des comparaisons binaires
  Serial.print("Décalage = ");
  Serial.println((message.etat[0]>>7)&1);
  Serial.print("Demande de retour message = ");
  Serial.println((message.etat[0]>>6)&1);
  Serial.print("flotteur bas = ");
  Serial.println((message.etat[0]>>5)&1);
  Serial.print("Flotteur haut = ");
  Serial.println((message.etat[0]>>4)&1);
  Serial.print("Electrovanne ville = ");
  Serial.println((message.etat[0]>>3)&1);
  Serial.print("Fenêtre = ");
  Serial.println((message.etat[0]>>2)&1);
  Serial.print("Barre de led = ");
  Serial.println((message.etat[0]>>1)&1);
  Serial.print("Arrosage = ");
  Serial.println((message.etat[0]>>0)&1);

  //Affiche les valeurs restantes 
  Serial.print("\nHumidité extérieure = ");
  Serial.println(message.humiditeExterieure);
  Serial.print("Humidité intérieure = ");
  Serial.println(message.humiditeInterieure);
  Serial.print("Humidité sol = ");
  Serial.println(message.humiditeSol);
  Serial.print("Température extérieure = ");
  Serial.println(message.temperatureExterieure/2-20);
  Serial.print("Température intérieure = ");
  Serial.println(message.temperatureInterieure/2-20);
  Serial.print("Luminosité = ");
  Serial.println(message.luminosite);

  Serial.println("\n---------------------\n");
}