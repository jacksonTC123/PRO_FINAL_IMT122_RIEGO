#include <WiFi.h>
#include <HTTPClient.h>
#include "funciones.h" 

void conectarWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Conectando a la red Wi-Fi...");
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("¡Conectado a Wi-Fi!");
}

void enviarDatosThingSpeak(int humedad1, int humedad2, const char* serverName, const char* apiKey) {
  String url = String(serverName) + "?api_key=" + apiKey + "&field1=" + String(humedad1) + "&field2=" + String(humedad2);
  
  // Enviar los datos a ThingSpeak usando HTTP
  HTTPClient http;
  http.begin(url);  // Inicia la conexión HTTP
  int httpCode = http.GET();  

  if (httpCode > 0) {
    Serial.println("Datos enviados a ThingSpeak");
  } else {
    Serial.println("Error al enviar datos a ThingSpeak");
  }
  http.end();
}
