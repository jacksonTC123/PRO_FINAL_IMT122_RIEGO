#include <WiFi.h>
#include <HTTPClient.h>
#include "funciones.h"

// Configuración de macros para WiFi y ThingSpeak
#define WIFI_SSID     "UCB"
#define WIFI_PASSWORD "IKb4rmBX2p8SNduLP0iIBxX#_"
#define TS_SERVER     "http://api.thingspeak.com/update"
#define TS_API_KEY    "Z520QZQNSWXBQVS3"

// Configuración de macros para pines y parámetros
#define SENSOR1_PIN   34 // GPIO34
#define SENSOR2_PIN   35 // GPIO35
#define SALIDA1_PIN   26 // GPIO26
#define SALIDA2_PIN   27 // GPIO27
#define DELAY_MS      3000 
#define UMBRAL_HUMEDAD 3000 // Umbral de humedad (%)
#define BAUDRATE 115200
#define SENSOR_SECO   4095 // Valor leído con suelo completamente seco
#define SENSOR_HUMEDO 2500 // Valor leído con suelo completamente húmedo

void setup() {
    Serial.begin(BAUDRATE);
    inicializarPines(SALIDA1_PIN, SALIDA2_PIN);
    conectarWiFi(WIFI_SSID, WIFI_PASSWORD);
}

void loop() {
    int lectura1 = leerSensor(SENSOR1_PIN);
    int lectura2 = leerSensor(SENSOR2_PIN);

    float humedad1 = convertirHumedad(lectura1, SENSOR_SECO, SENSOR_HUMEDO);
    float humedad2 = convertirHumedad(lectura2, SENSOR_SECO, SENSOR_HUMEDO);

    imprimirLecturas(humedad1, humedad2);

    controlarSalida(humedad1, SALIDA1_PIN, UMBRAL_HUMEDAD);
    controlarSalida(humedad2, SALIDA2_PIN, UMBRAL_HUMEDAD);

    enviarDatosThingSpeak(TS_SERVER, TS_API_KEY, humedad1, humedad2);

    delay(DELAY_MS); 
}
