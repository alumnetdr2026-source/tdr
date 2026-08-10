#include <Adafruit_NeoPixel.h>

#define pinLED 6
#define NUMPIXELS 30

Adafruit_NeoPixel tira(NUMPIXELS, pinLED, NEO_GRB + NEO_KHZ800);

void setup() {

  tira.begin();
  tira.show();

  Serial.begin(9600);
}

void loop() {

  int v = analogRead(A0);

  // El valor 600 s'ha d'ajustar segons la llum del taller
  // poca llum -> v petit, molta llum -> v gran

  if (v < 600) {
    // NIT -> blanc càlid
    for (int i = 0; i < NUMPIXELS; i++) {
      tira.setPixelColor(i, tira.Color(255, 160, 60));
    }
    tira.show();
  }
  else {
    // DIA -> verd
    for (int i = 0; i < NUMPIXELS; i++) {
      tira.setPixelColor(i, tira.Color(0, 120, 0));
    }
    tira.show();
  }

  Serial.println(v);
}