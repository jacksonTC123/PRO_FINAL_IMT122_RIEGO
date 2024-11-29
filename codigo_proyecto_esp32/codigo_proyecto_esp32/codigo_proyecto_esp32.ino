#include <WiFi.h>
#include <HTTPClient.h>
#include "funciones.h"  

// Definición de configuraciones (Wi-Fi y API Key)
#define SSID "UCB"               // Nombre de la red Wi-Fi
#define PASSWORD "IKb4rmBX2p8SNduLP0iIBxX#_"  // Contraseña de la red Wi-Fi
#define SERVER_NAME "http://api.thingspeak.com/update"  // URL de ThingSpeak
#define API_KEY "7WH890SIWHLe5CIE" // API Key de ThingSpeak

#define SENSOR_HUMEDAD_1 A0  // Sensor de humedad 1
#define SENSOR_HUMEDAD_2 A1  // Sensor de humedad 2
#define ENVIAR_INTERVALO 15000  // 15 segundos

void setup() {
  Serial.begin(115200);
  conectarWiFi(SSID, PASSWORD);
}

void loop() {
  int humedad1 = analogRead(SENSOR_HUMEDAD_1);
  int humedad2 = analogRead(SENSOR_HUMEDAD_2);
  
  Serial.print("Humedad Sensor 1: ");
  Serial.println(humedad1);
  Serial.print("Humedad Sensor 2: ");
  Serial.println(humedad2);
  enviarDatosThingSpeak(humedad1, humedad2, SERVER_NAME, API_KEY);

  delay(ENVIAR_INTERVALO);
}
