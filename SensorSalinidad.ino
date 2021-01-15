#define MAXVALUE 26400
#define MINVALUE 4
#include "SensorSalinidad.h"
#include <Wire.h>
SensorSalinidad::SensorSalinidad(int pin_canal_ads, int pinSalida)
: pinADS(pin_canal_ads), maxValue(MAXVALUE), minValue(MINVALUE), pinSalida(pinSalida)
{
  pinMode(pinSalida, OUTPUT);
  }
void SensorSalinidad::setADS(Adafruit_ADS1115 address){
  direccion= address;
}
int SensorSalinidad::getSalinidad(){
  int16_t adc0;
  digitalWrite( pinSalida, HIGH);
  //
  //leemos la tension que mide el cable
  adc0 = direccion.readADC_SingleEnded(pinADS);

  digitalWrite(pinSalida, LOW);
  
  if(adc0 > maxValue){
    maxValue = adc0;
  }
  if(adc0 < minValue){
    minValue = adc0;
  }
  /*
  maxValue = 26400;
  minValue = 4;
  */
  //obtenemos el resultado en porcentaje a partir de las medias maximas y minimas
  int result = map(adc0, minValue, maxValue, 0, 100);
  return result;
}
