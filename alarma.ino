int pir= 7;
int led= 2;
int ldr= A0; 

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int llum = analogRead(ldr); 
  bool nit = (llum < 500);         

  if (nit)
  {
    Serial.println("Nit");
  }
  else
  {
    Serial.println("Dia");
  }

  if (digitalRead(pir) == HIGH && nit)
  {
    digitalWrite(led, HIGH);
    Serial.println("Encès");
    delay(200);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("Apagat");
    delay(200);
  }
}