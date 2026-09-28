#include "CSigFox.h" //appelle la classe sigfox qui est le point central de tout le code.
#include <SigFox.h> //appelle la bibliothèque SigFox
#define DEBUG 1 // défini le debug à 1, cela permet de passer la commande SigFox.endPacket()

/*************************************************/
// Nom du projet:Serre connectée
// Nom du fichier:serreConnectee.ino
// Version : 1.1
// Nom du programmeur:Groupe serre connectée 2021/2022, Luc VALETTE
// Date de création:2022
// Rôle du fichier:Fichier main du projet
// Nom des composants utilises:/
// Historique du fichier:modifié le 31/05/2023
/*************************************************/
/*
pins utilisés :
  flotteurs : 3, 4, 5V
  humidite : A1, A2, 11, 12, 5V, gnd
  temperature : A3, 11, 12, 5V, gnd
  luminosite : 11, 12, 13, 5V, gnd
  arrosage : 0, 5V, gnd
  fenetre : 1, 2, gnd
*/

void setup(){
  Serial.begin(9600); //initialise la communication série avec une vitesse de transmission de données de 9600 bits par seconde.
  delay(2000);
  delay(10*1000); //permet d'avoir quelques secondes d'attente avant de lancer le programme réellement. Cela permet d'avoir le temps de changer de programme si celui qui est sur la carte ne fonctionne pas
  if (!SigFox.begin()) { //initialise la communication entre la carte arduino et le module SigFox et vérifie la connexion
    Serial.println("Communication SigFox impossible");
    while(1);
  }
  if (DEBUG) {
    SigFox.debug(); //active le mode deboggage de la carte
  }
  delay(1000);
  Serial.println("dab");
}

sigFoxMessage message;
CSigFox module;
/*
message SigFox :
  char etat[1] = demande retour message, état flotteur haut, état flotteur bas, état électrovanne ville, état moteur, état barre led, état électrovanne, false
  uint8_t humiditeExterieure
  uint8_t humiditeInterieure
  uint8_t humiditeSol
  uint8_t temperatureExterieure
  uint8_t temperatureInterieure
  int luminosite;
}sigFoxMessage;
*/

void loop(){
  module.newValeurs(); //met à jours les valeurs des capteurs et lance les actionneurs si besoin
  module.newMessage(&message); //place les valeurs des capteurs dans le message à envoyer sur le réseau sigfox
  module.envoiTrame(message); //envoie le message sur le réseau sigfox
  delay(15*60*1000);//attend 15 minutes, a remplacer à la fin par LowPower.sleep(15*60*1000);
}