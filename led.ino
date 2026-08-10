// Detector de llum amb LDR

#define pinLED 12

void setup() {

  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int v = analogRead(A0);
  // El valor 600 (següent línia) s'ha d'ajustar depenent de la llum al taller
  // i del valor de la resistència pull-down
  // poca llum -> v petit, molta llum -> v gran
  if (v < 600) digitalWrite(pinLED, HIGH);
  else digitalWrite(pinLED, LOW);
  Serial.println(v);
}