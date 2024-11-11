#include <Arduino.h>
#include "funciones.h"

int nivelAgua = 0;
int humedadSuelo = 0;

void iniciarComunicacionSerial() {
  Serial.begin(BAURATE);
}

void inicializarSensores() {
  pinMode(PIN_SENSOR_NIVEL_AGUA, INPUT);
  pinMode(PIN_SENSOR_HUMEDAD, INPUT);
}

void leerSensores() {
  nivelAgua = analogRead(PIN_SENSOR_NIVEL_AGUA);
  humedadSuelo = analogRead(PIN_SENSOR_HUMEDAD);
  
  Serial.print("Nivel de agua: ");
  Serial.println(nivelAgua);
  
  Serial.print("Humedad del suelo: ");
  Serial.println(humedadSuelo);
}

void activarActuador() {
  if (nivelAgua < 200) {
    Serial.println("Activando bomba de agua");
  } else {
    Serial.println("Nivel de agua adecuado.");
  }

  if (humedadSuelo < 100) {
    Serial.println("Activando sistema de riego");
  } else {
    Serial.println("Suelo suficientemente húmedo");
  }
}

void configurarSistema() {
  Serial.println("Configurando sistema");
}
