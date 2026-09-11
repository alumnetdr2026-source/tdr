#include <WiFi.h> 
#include <WebServer.h> 
 
const char* ssid = ""; 
const char* password = ""; 

const int SENSOR = 25; 

WebServer server(80); 

void paginaWeb() { 
 
  // El sensor dona LOW quan està premut 
  bool ocupada = (digitalRead(SENSOR) == LOW); 
 
  String estat; 
  String color; 
 
  if (ocupada) { 
 
    estat = "OCUPADA"; 
    color = "#e74c3c"; 
 
  } else { 
 
    estat = "LLIURE"; 
    color = "#2ecc71"; 
 
  } 
 
 
  String html = R"rawliteral( 
 
<!DOCTYPE html> 
 
<html lang="ca"> 
 
<head> 
 
<meta charset="UTF-8"> 
 
<meta name="viewport" 
      content="width=device-width, initial-scale=1.0"> 
 
<meta http-equiv="refresh" content="2"> 
 
<title>Aparcament</title> 
 
<style> 
 
body { 
    font-family: Arial, sans-serif; 
    background-color: #f2f2f2; 
    text-align: center; 
    margin: 0; 
    padding-top: 50px; 
} 
 
h1 { 
    color: #333; 
} 
 
.plaça { 
 
    width: 300px; 
 
    margin: 40px auto; 
 
    padding: 40px 20px; 
 
    border-radius: 20px; 
 
    background-color: )rawliteral" + color + R"rawliteral(; 
 
    color: white; 
 
    font-size: 30px; 
 
    font-weight: bold; 
 
    box-shadow: 0px 5px 15px rgba(0,0,0,0.2); 
 
} 
 
.numero { 
 
    font-size: 20px; 
 
    margin-bottom: 20px; 
 
} 
 
 
 
</style> 
 
</head> 
 
 
<body> 
 
<h1>APARCAMENT</h1> 
 
 
<div class="plaça"> 
 
    <div class="numero"> 
        PLAÇA 1 
    </div> 
 
    )rawliteral" + estat + R"rawliteral( 
 
</div> 
</body> 
 
</html> 
 
)rawliteral"; 
 
 
  server.send(200, "text/html", html); 
} 
 
 

void setup() { 
 
  Serial.begin(115200); 
 
 
  // Configurar el sensor 
 
  pinMode(SENSOR, INPUT); 
 
 
  // Connectar a WiFi 
 
  WiFi.begin(ssid, password); 
 
 
  Serial.println(); 
 
  Serial.print("Connectant a WiFi"); 
 
 
  while (WiFi.status() != WL_CONNECTED) { 
 
    delay(500); 
 
    Serial.print("."); 
 
  } 
 
 
  Serial.println(); 
 
  Serial.println("WiFi connectada!"); 
 
  Serial.print("Adreça IP de l'ESP32: "); 
 
  Serial.println(WiFi.localIP()); 
 
 
  server.on("/", paginaWeb); 
 
  server.begin(); 
 
 
  Serial.println("Servidor web iniciat!"); 
 
} 
 
 
void loop() { 
 
  server.handleClient(); 
 
}