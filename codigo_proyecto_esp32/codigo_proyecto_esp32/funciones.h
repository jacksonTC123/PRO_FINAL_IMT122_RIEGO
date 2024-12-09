#ifndef FUNCIONES_H
#define FUNCIONES_H

void conectarWiFi(const char* ssid, const char* password);
void inicializarPines(int pin1, int pin2);
int leerSensor(int pin);
float convertirHumedad(int lectura, int seco, int humedo);
void imprimirLecturas(float humedad1, float humedad2);
void controlarSalida(float humedad, int pinSalida, int umbral);
void enviarDatosThingSpeak(const char* server, const String& apiKey, float humedad1, float humedad2);

#endif // FUNCIONES_H
