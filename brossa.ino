#include <Servo.h>
 /*
Sensor d'Ultrasons: Avís lluminós de proximitat
En apropar un objecte al sensor a menys del límit especificat (10cm) s'encén un LED.
El so es desplaça a 1cm cada 29,2 microsegons, però per evitar el ralentiment que provoca el processament
de números decimals utilitzem la fórmula "distancia=duracio*10/292/2" en lloc de "distancia=duracio/29.2/2"
 */
 Servo servo1;
int TriggerPin = 3;
int EchoPin = 4;
int limit = 5;                         //límit en cm especificat per obrir la brossa
long duracio = 0;
long distancia = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  servo1.attach(13);
}
 
void loop() {
  digitalWrite(TriggerPin, LOW);        //iniciem el disparador amb LOW durant 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);       //activem el Trigger durant 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  duracio = pulseIn(EchoPin, HIGH);    //mesurem el temps entre pulsos, en microsegons
  distancia = duracio * 10 / 292/ 2;   //convertim a distancia a centímetres
    if (distancia >= 500 || distancia <= 0)
          {                                // si la distància és major de 500cm o menor de 0cm 
          Serial.println("Fora de rang");  // no mesura res
          }
    else  {
          if (distancia <= limit && distancia >= 1)
              {
              servo1.write(90);     // encén el led si la distància és menor del límit especificat
              Serial.print("Distancia: ");  // envia el valor de la distància pel port serie
              Serial.print(distancia);          
              Serial.println("cm. --> S'obre la brossa");
              }
          else {
              Serial.print("Distancia: ");   // envia el valor de la distància pel port serie
              Serial.print(distancia);         
              Serial.println("cm.");           
              servo1.write(0);      // tanca la brossa si la distància és najor del límit especificat
              }
          }   
  delay(500);
}