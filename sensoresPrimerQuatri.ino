//llibreries dels sensors a utilitzar
#include "sensorSalinidad.h"
#include "sensorHumedad.h"
#include "sensorTemperatura.h"
// faltan las direcciones del pin #define PIN_ADS1115_SENSOR_SALINIDAD 0 en cada uno de los sensores
//llibreria per accedir a la memoria del sparkfun
#include <EEPROM.h>
// constructor del ads1115 en la direccio 0x48
Adafruit_ADS1115 ads1115(0x48); 
void setup() {
  setupHumedad();//cargamos la configuracion inicial del sensor de humedad
  setupSalinidad();//cargamos la configuracion inicial del sensor de salinidad
  setupTemperatura();// cargamos la configuracion inial del sensor de temperatura
}

void loop() {
  //llamaremos a las funciones para ver los valores de los sensores cada 5 segundos
  //
  //mostramos el porcentaje de humedad actual
  Serial.print("Porcentaje de humedad: ");
  Serial.print(loopHumedad());//nombre de la funcion cambiado y ahora es parametrizada
  Serial.println("%");
  //
  //mostramos el porcentaje de salinidad actual
  Serial.print("Porcentaje de salinidad: ");
  Serial.print(loopSalinidad());
  Serial.println("%");
  //
  //mostramos la temperatura actual
  Serial.print("Temperatura: ");
  Serial.print(loopTemperatura());
  Serial.println("º");
  //
  //mandamos a dormir el dispositivo durante 5 segundos para ahorrar energia
  ESP.deepSleep(5/10^-6);
}
