 
#include "TransmissionSigfox.h"
#define DEBUG 1

  int analogPin = A5;   // potentiometer connected to analog pin 3
  int electrovanne = A6;
  
DallasTemperature sensors(&oneWire);
DFRobot_B_LUX_V30B mylux(13);

void setup()
{
   // sets the pin as output
  mylux.begin();
  Serial.begin(9600);
    if (DEBUG){

    while (!Serial) {
      sensors.begin();//temp
    }
  }
// Initialize the SigFox module
  if (!SigFox.begin()) {

  }
// If we wanto to debug the application, print the device ID to easily find it in the backend
  if (DEBUG){
    SigFox.debug();
  }
  delay(100);
  
}

  int statut = 0;
  TransmissionSigfox TrSigfox;
  
  sigfox_message message = { 0 , 0 , 0, 0, false, false};
                             

void loop(){

      TrSigfox.RefreshTrameSigfox();
  
      message = TrSigfox.TrameSigfox(message);
statut = TrSigfox.EnvoieTrameSigfox(message);

  pinMode(analogPin, OUTPUT);
  pinMode(electrovanne, OUTPUT); 
 if(message.Hum > 1) {
 digitalWrite(analogPin,HIGH);
 digitalWrite(electrovanne,HIGH);
  delay(5000);
   digitalWrite(electrovanne, LOW);
    digitalWrite(analogPin,LOW);
 }
 else
 {
  digitalWrite(electrovanne, LOW);
    digitalWrite(analogPin,LOW);
 }

      Serial.print("Statut : ");
        Serial.println(statut);

      Serial.print("Message : ");
        Serial.println(message.Flo);

      LowPower.sleep(15 * 60 * 1000);
     }
