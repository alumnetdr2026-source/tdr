#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 8
#define DHTTYPE DHT11

int led=12; 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(led, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  float temperatura = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("TEMPERATURA");

  display.setTextSize(2);
  display.setCursor(0, 15);
  display.print(temperatura);
  display.print(" C");

  if (temperatura > 35) {
    display.setTextSize(1);
    display.setCursor(0, 35);
    display.print("Alerta de calor: hidrata't i evita l'exposició al sol.");
    display.display();

    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  } 
  else {
    display.display();
    digitalWrite(led, LOW);
    delay(1000);
  }
}