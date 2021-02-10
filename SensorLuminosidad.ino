#include "SensorLuminosidad.h"
#define MAXVALUE 800
#define MINVALUE 0

SensorLuminosidad::SensorLuminosidad(int pin_canal_ads)
: pinADS(pin_canal_ads), maxValue(MAXVALUE), minValue(MINVALUE){
}
void SensorLuminosidad::setADS(Adafruit_ADS1115 address){
  direccion= address;
}
int SensorLuminosidad::getLuminosidad() {
  int16_t adc3;
  adc3 = direccion.readADC_SingleEnded(pinADS);
  if(adc3 > maxValue){
    maxValue = adc3;
  }
  if(adc3 < 0)
    minValue = adc3;
  Serial.print("Luminosidad: ");
  Serial.println(adc3);
  return map(adc3, minValue, maxValue, 0, 100);
}
