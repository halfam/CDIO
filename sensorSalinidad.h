#define salinity_power_pin 5
#include <Wire.h>
#include <Adafruit_ADS1015.h>

void setupSalinidad() {

  pinMode(salinity_power_pin, OUTPUT);
}

int result = 0;
int maxValue = 26400;
int minValue = 4;
//
//se manda una señal desde un pin de salida y desde un pin de entrada leemos
//la tension que llega debe variar segun la resistencia del "conductor"
//el agua no es conductora pero al echar sal (que si es conductora) recibiremos señal
int leerSalinidad(Adafruit_ADS1115 address,int pin_canal_ads) {
  int16_t adc0;
  digitalWrite( salinity_power_pin, HIGH);
  //
  //leemos la tension que mide el cable
  adc0 = address.readADC_SingleEnded(pin_canal_ads);

  digitalWrite(salinity_power_pin, LOW);
  
  if(adc0 > maxValue){
    maxValue = adc0;
  }
  if(adc0 < minValue){
    minValue = adc0;
  }
  //
  //obtenemos el resultado en porcentaje a partir de las medias maximas y minimas
  result = map(adc0, minValue, maxValue, 0, 100);
  return result;
}
