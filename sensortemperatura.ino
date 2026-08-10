#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  float temperatura = dht.readTemperature();
  float humitat = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  Serial.print("Humitat: ");
  Serial.print(humitat);
  Serial.println(" %");

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);


  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("TEMPERATURA");

  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(temperatura);
  display.print(" C");


  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("HUMITAT");

  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(humitat);
  display.print("%");

  display.display();

  delay(2000);
}