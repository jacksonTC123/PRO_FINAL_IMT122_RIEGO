#include <WiFi.h>
#include <HTTPClient.h>
#include "funciones.h"

void conectarWiFi(const char* ssid, const char* password) {
    Serial.print("Conectando a WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" Conectado a WiFi.");
}

void inicializarPines(int pin1, int pin2) {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

int leerSensor(int pin) {
    return analogRead(pin);
}

float convertirHumedad(int lectura, int seco, int humedo) {
    if (lectura > seco) lectura = seco;
    if (lectura < humedo) lectura = humedo;
    return 100.0 * (float)(seco - lectura) / (seco - humedo);
}

void imprimirLecturas(float humedad1, float humedad2) {
    Serial.print("Humedad Sensor 1: ");
    Serial.print(humedad1);
    Serial.println("%");
    Serial.print("Humedad Sensor 2: ");
    Serial.print(humedad2);
    Serial.println("%");
}

void controlarSalida(float humedad, int pinSalida, int umbral) {
    if (humedad < umbral) {
        digitalWrite(pinSalida, HIGH);
        Serial.println("Salida activada.");
    } else {
        digitalWrite(pinSalida, LOW);
        Serial.println("Salida desactivada.");
    }
}

void enviarDatosThingSpeak(const char* server, const String& apiKey, float humedad1, float humedad2) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = String(server) + "?api_key=" + apiKey +
                     "&field1=" + String(humedad1, 2) +
                     "&field2=" + String(humedad2, 2);
        
        http.begin(url);
        int httpCode = http.GET();
        if (httpCode > 0) {
            Serial.println("Datos enviados a ThingSpeak.");
        } else {
            Serial.println("Error al enviar datos a ThingSpeak.");
        }
        http.end();
    } else {
        Serial.println("WiFi desconectado. No se pudieron enviar los datos.");
    }
}
