#include "SensorLuminosidad.h"
#define MAXVALUE 800
#define MINVALUE 150

SensorLuminosidad::SensorLuminosidad(int pin_canal_ads)
: pinADS(pin_canal_ads), maxValue(MAXVALUE), minValue(MINVALUE){
}
void SensorLuminosidad::setADS(Adafruit_ADS1115 address){
  direccion= address;
}
int SensorLuminosidad::getLuminosidad() {
  int16_t adc3;
  adc3 = direccion.readADC_SingleEnded(pinADS);
  if(adc3 >= maxValue)
    return 0;
  if(adc3 < maxValue and adc3 > minValue)
    return 1;
  if(adc3 <= minValue)
    return 2; 
}
