void setup(){
  Serial.begin(9600);
  delay(10*1000);
}

void loop(){
  Serial.println("Je suis un programme qui attend 10 secondes et envoie ce message");
  delay(10*1000);
}
