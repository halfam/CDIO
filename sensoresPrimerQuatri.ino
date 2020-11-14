//Añadimos los otros programas.
#include "sensorSalinidad.h"
#include "sensorHumedad.h"


void setup() {
  setupHumedad();//cargamos la configuracion inicial del sensor de humedad
  setupSalinidad();//cargamos la configuracion inicial del sensor de salinidad
}

void loop() {
  //llamaremos a las funciones para ver los valores de los sensores cada 5 segundos
  //
  //mostramos el porcentaje de humedad actual
  Serial.print("Porcentaje de humedad: ");
  Serial.print(loopHumedad());
  Serial.println("%");
  //
  //mostramos el porcentaje de salinidad actual
  Serial.print("Porcentaje de salinidad: ");
  Serial.print(loopSalinidad());
  Serial.println("%");
  //
  //
  delay(5000);
}

//Programa realizado por todos los integrantes del equipo y perfeccionado por Joan Altur.
