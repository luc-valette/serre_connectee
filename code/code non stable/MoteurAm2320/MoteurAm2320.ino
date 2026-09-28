#include "CChaleur.h"
#include "CAm2320.h"
#include <ArduinoLowPower.h>

void prez(CChaleur motor, CAm2320 captor){
  Serial.print("Température du capteur = ");
  Serial.println(captor.valeurTemperature());
  Serial.print("Température du moteur = ");
  Serial.println(motor.valeurTemperatureActuelle());
  Serial.print("Fenetre = ");
  Serial.println(motor.valeurFenetre());
  Serial.println("\n/****************************************************************************/\n");
}

void setup() {
  Serial.begin(9600);
  delay(10*1000);
}

CChaleur moteur(1,2,16,18);
CAm2320 capteur;

void loop() {
  capteur.changerValeurCapteur();
  Serial.println("J'ai récup la valeur du capteur");
  moteur.changerValeurTemperature(capteur.valeurTemperature());
  Serial.println("J'ai changé la valeur du capteur dans le moteur pour qu'il s'ouvre");
  prez(moteur,capteur);
  moteur.ouvrirSiBesoin();
  prez(moteur,capteur);
  LowPower.sleep(20*60*1000);
  moteur.changerValeurTemperature(15);
  Serial.println("J'ai changé la valeur du capteur dans le moteur pour qu'il se ferme");
  prez(moteur,capteur);
  moteur.ouvrirSiBesoin();
  prez(moteur,capteur);
  LowPower.sleep(20*60*1000);
}