#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definición de macros para los pines de los sensores
#define PIN_SENSOR_NIVEL_AGUA A0
#define PIN_SENSOR_HUMEDAD A1
#define BAURATE 9600

void iniciarComunicacionSerial();
void inicializarSensores();
void leerSensores();
void activarActuador();
void configurarSistema();

#endif
