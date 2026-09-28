#include "CSigFox.h"
#include <SigFox.h>
#include <ArduinoLowPower.h>

#define DEBUG 1

void setup() {
  Serial.begin(9600);
  delay(15 * 1000);
  if (!SigFox.begin()) {
    Serial.println("Communication SigFox impossible");
    while (1);
  }
  if (DEBUG) {
    SigFox.debug();
  }
  delay(1000);
}

sigFoxMessage message;
CSigFox module;

void loop() {
  delay(1000);
  module.nouvellesValeurs();
  module.nouveauMessage(&message);
  module.envoiTrame(message);
  LowPower.sleep(19 * 60 * 1000);
}