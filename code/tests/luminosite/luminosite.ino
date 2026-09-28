#include "CLuminosite.h"

void setup() {
  Serial.begin(9600);
}

CLuminosite capteur(13);

void loop() {
  capteur.changerValeurCapteur();
  Serial.print("Luminosité = ")
  Serial.print(capteur.valeurLuminosite());
  Serial.println("lux");
}
