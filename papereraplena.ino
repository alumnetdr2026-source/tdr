int crash = 13;

int vermell =  10;
int verd = 6;
int blau = 3;

void setup() {
  pinMode(crash, INPUT);

  pinMode(vermell, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(blau, OUTPUT);
}

void loop() {
  int estat = digitalRead(crash);

  if (estat == HIGH) {
    digitalWrite(vermell, LOW);
    digitalWrite(verd, HIGH);
    digitalWrite(blau, LOW);
  }
  else {
    digitalWrite(vermell, HIGH);
    digitalWrite(verd, LOW);
    digitalWrite(blau, LOW);
  }
}