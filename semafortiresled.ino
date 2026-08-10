#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMLEDS 30

Adafruit_NeoPixel tira(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

int verd1 = 4;
int groc1 = 3;
int vermell1 = 2;
int boto1 = 10;

int temps = 2000;

void setup() {
  pinMode(verd1, OUTPUT);
  pinMode(groc1, OUTPUT);
  pinMode(vermell1, OUTPUT);

  pinMode(boto1, INPUT);

  tira.begin();
  tira.show();

  // INICI: vianants vermell
  for (int i = 0; i < NUMLEDS; i++) {
    tira.setPixelColor(i, tira.Color(255, 0, 0));
  }
  tira.show();

  digitalWrite(verd1, HIGH);
  digitalWrite(groc1, LOW);
  digitalWrite(vermell1, LOW);
}

void loop() {

  if (digitalRead(boto1) == HIGH) {

    // groc semàfor
    digitalWrite(verd1, LOW);
    digitalWrite(groc1, HIGH);
    delay(temps);

    // vermell semàfor + vianants VERD
    digitalWrite(groc1, LOW);
    digitalWrite(vermell1, HIGH);

    for (int i = 0; i < NUMLEDS; i++) {
      tira.setPixelColor(i, tira.Color(0, 255, 0));
    }
    tira.show();

    delay(10000);

    // verd semàfor + vianants VERMELL
    digitalWrite(vermell1, LOW);
    digitalWrite(verd1, HIGH);

    for (int i = 0; i < NUMLEDS; i++) {
      tira.setPixelColor(i, tira.Color(255, 0, 0));
    }
    tira.show();

    delay(10000);
  }

}