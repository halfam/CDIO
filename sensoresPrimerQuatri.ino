//llibreries dels sensors a utilitzar
#include "sensorSalinidad.h"
#include "sensorHumedad.h"
#include "sensorTemperatura.h"
// faltan las direcciones del pin #define PIN_ADS1115_SENSOR_SALINIDAD 0 en cada uno de los sensores
#define PIN_ADS1115_SENSOR_SALINIDAD 0 
#define PIN_ADS1115_SENSOR_HUMEDAD 1 
#define PIN_ADS1115_SENSOR_TEMPERATURA 2

//llibreria per accedir a la memoria del sparkfun
#include <EEPROM.h>
// constructor del ads1115 en la direccio 0x48
Adafruit_ADS1115 ads1115(0x48); 
void setup() {
  Serial.begin(9600);
  ads1115.begin();
  ads1115.setGain(GAIN_ONE);
  setupHumedad();//cargamos la configuracion inicial del sensor de humedad
  setupSalinidad();//cargamos la configuracion inicial del sensor de salinidad
  setupTemperatura();// cargamos la configuracion inial del sensor de temperatura
  delay(1000);
}

void loop() {
  //llamaremos a las funciones para ver los valores de los sensores cada 5 segundos
  //
  //mostramos el porcentaje de humedad actual
  Serial.print("Porcentaje de humedad: ");
  Serial.print(leerHumedad(ads1115, PIN_ADS1115_SENSOR_HUMEDAD));//nombre de la funcion cambiado y ahora es parametrizada
  Serial.println("%");
  //
  //mostramos el porcentaje de salinidad actual
  Serial.print("Porcentaje de salinidad: ");
  Serial.print(leerSalinidad(ads1115, PIN_ADS1115_SENSOR_SALINIDAD));
  Serial.println("%");
  //
  //mostramos la temperatura actual
  Serial.print("Temperatura: ");
  Serial.print(leerTemperatura(ads1115, PIN_ADS1115_SENSOR_TEMPERATURA));
  Serial.println("º");
  //
  //mandamos a dormir el dispositivo durante 5 segundos para ahorrar energia
  ESP.deepSleep(60*1000);
  //delay(5000);
}
