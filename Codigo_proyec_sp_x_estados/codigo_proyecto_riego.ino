#include <Arduino.h>
#include "funciones.h"

enum Estado {
  SLEEP,
  SENSADO,
  ACTUADOR,
  CONFIGURACION
};

Estado maquina = SLEEP;

void setup() {
  iniciarComunicacionSerial();
  inicializarSensores();
}

void loop() {
  switch (maquina) {
    case SLEEP:
      Serial.println("Estado: SLEEP");
      delay(1000);
      maquina = SENSADO;
      break;

    case SENSADO:
      Serial.println("Estado: SENSADO");
      leerSensores();
      maquina = ACTUADOR;
      break;

    case ACTUADOR:
      Serial.println("Estado: ACTUADOR");
      activarActuador();
      maquina = CONFIGURACION;
      break;

    case CONFIGURACION:
      Serial.println("Estado: CONFIGURACION");
      configurarSistema();
      maquina = SLEEP;
      break;
  }
}
