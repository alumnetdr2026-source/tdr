#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int boto1 = 2;
int boto2 = 3;

Servo servo;
int servoPin = 9;

int persones = 0;

void setup() {
  pinMode(boto1, INPUT);
  pinMode(boto2, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  servo.attach(servoPin);
  servo.write(0);
}

void loop() {

  if (digitalRead(boto1) == HIGH) {
    if (persones < 10) {
      persones++;
      servo.write(90);
      delay(2000);
      servo.write(0);
    }
  }

  if (digitalRead(boto2) == HIGH) {
    if (persones > 0) {
      persones--;
      servo.write(90);
      delay(2000);
      servo.write(0);
    }
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

  if (persones > 10) {
    display.println("Aforament complet");
  } else {
    display.print("Persones: ");
    display.println(persones);
  }

  display.display();
}