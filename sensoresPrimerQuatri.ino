//llibreries dels sensors a utilitzar
#include "SensorSalinidad.h"
#include "SensorHumedad.h"
#include "SensorTemperatura.h"
#include "SensorLuminosidad.h"
#include "wifi.h"
//definicion pin de conexiones al adc de cada sensor
#define PIN_ADS1115_SENSOR_SALINIDAD 2
#define PIN_ADS1115_SENSOR_HUMEDAD 1 
#define PIN_ADS1115_SENSOR_TEMPERATURA 0
#define PIN_ADS1115_SENSOR_LUMINOSIDAD 3

//llibreria per accedir a la memoria del sparkfun
#include <EEPROM.h>
// constructor del ads1115 en la direccio 0x48
 Adafruit_ADS1115 ads1115(0x48);
 //creando los sensores
 SensorHumedad humedad( PIN_ADS1115_SENSOR_HUMEDAD);
 SensorSalinidad sal( PIN_ADS1115_SENSOR_SALINIDAD, 5);
 SensorTemperatura temperatura(PIN_ADS1115_SENSOR_TEMPERATURA);
 SensorLuminosidad luminosidad(PIN_ADS1115_SENSOR_LUMINOSIDAD);
void setup() {
  
  Serial.begin(9600);
  ads1115.begin();
  ads1115.setGain(GAIN_ONE);
  pinMode(16, WAKEUP_PULLUP);
  
  humedad.setADS(ads1115);
  sal.setADS(ads1115);
  temperatura.setADS(ads1115);
  luminosidad.setADS(ads1115);
 setupWifi();
}

void loop() {
  String data[ 4 + 1];
  //llamaremos a las funciones para ver los valores de los sensores cada 5 segundos
  //
  //mostramos el porcentaje de humedad actual
  Serial.print("Porcentaje de humedad: ");
  //Serial.print(leerHumedad(ads1115, PIN_ADS1115_SENSOR_HUMEDAD));//nombre de la funcion cambiado y ahora es parametrizada
  data[1] = String(humedad.getHumedad());
  Serial.print(data[1]);
  Serial.println("%");
  //
  //mostramos el porcentaje de salinidad actual
  Serial.print("Porcentaje de salinidad: ");
  data[2] = String(sal.getSalinidad());
  Serial.print(data[2]);
  Serial.println("%");
  //
  //mostramos la temperatura actual
  Serial.print("Temperatura: ");
  data[3] = String(temperatura.getTemperatura());
  Serial.print(data[3]);
  Serial.println("º");
  //
  //mostramos los valores de luminosidad
  int lumi = luminosidad.getLuminosidad();
  //data[4] = String(lumi);
  data[4] = String(lumi); 
  //
  //mandamos a dormir el dispositivo durante 5 segundos para ahorrar energia
  HTTPPost( data, 4 );
  //loopWifi();
  delay(3000);
  WiFi.disconnect();
  delay(2000);
  ESP.deepSleep(5e6);
  delay(1000);
  //delay(3000);
 
  

}
