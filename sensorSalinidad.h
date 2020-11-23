#define salinity_power_pin 5
#include <Wire.h>
#define PIN_ADS1115_SENSOR_SALINIDAD 0 

void setupSalinidad() {
  Serial.begin(9600);
  ads1115.begin(); //Initialize ads1115
  ads1115.setGain(GAIN_ONE);
  pinMode(salinity_power_pin, OUTPUT);
}

int result = 0;
//
//se manda una señal desde un pin de salida y desde un pin de entrada leemos
//la tension que llega debe variar segun la resistencia del "conductor"
//el agua no es conductora pero al echar sal (que si es conductora) recibiremos señal
int loopSalinidad() {
  int16_t adc0;
  digitalWrite( salinity_power_pin, HIGH);
  //
  //leemos la tension que mide el cable
  adc0 = ads1115.readADC_SingleEnded(PIN_ADS1115_SENSOR_SALINIDAD);
  digitalWrite(salinity_power_pin, LOW);
  //
  //obtenemos el resultado en porcentaje a partir de las medias maximas y minimas
  result = map(adc0, 6, 26364, 0, 100);
  if( result == 1)//el progrmama muestra un "error" de 1% en el uso del sensor
    result = 0;
   
  return result;
}
