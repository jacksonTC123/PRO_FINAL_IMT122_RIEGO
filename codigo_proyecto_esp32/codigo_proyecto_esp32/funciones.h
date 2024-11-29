#ifndef FUNCIONES_H
#define FUNCIONES_H

void conectarWiFi(const char* ssid, const char* password);
void enviarDatosThingSpeak(int humedad1, int humedad2, const char* serverName, const char* apiKey);

#endif
