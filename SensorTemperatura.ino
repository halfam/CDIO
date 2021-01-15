#include "SensorTemperatura.h"
#define SERIESRESISTOR 2200
#define CONSTANTE 7999.76
#define B 0.79
#define M 0.035

SensorTemperatura::SensorTemperatura(int pinADS)
:pinADS(pinADS)
{}

void SensorTemperatura::setADS(Adafruit_ADS1115 address){
  direccion= address;
}

int SensorTemperatura::getTemperatura(){
  int16_t adc;
  adc = direccion.readADC_SingleEnded(pinADS);
  float a = CONSTANTE *adc;
  float vo = a /CONSTANTE;
  float temperatura =(vo- B*CONSTANTE)/(M*CONSTANTE);
  return temperatura;
}
