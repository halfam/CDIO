#include "SensorHumedad.h"
#define AIRVALUE 30360 // Medimos valor en seco (calibrado)
#define WATERVALUE 17705 // Medimos valor en agua inicial (calibrado)

SensorHumedad::SensorHumedad(int pin_canal_ads)
:  pinADS(pin_canal_ads), airValue(AIRVALUE), waterValue(WATERVALUE)
{}
void SensorHumedad::setADS(Adafruit_ADS1115 address){
   direccion= address;
}
int SensorHumedad::getPorcentajeHumedad() {
//inicialitzacion variables
int16_t adc;
adc = direccion.readADC_SingleEnded(pinADS);
//Serial.println(adc0);
//
//la calibración tiene un 99% de precision por lo que los valores de porcentaje muestran
//unos extremos de 101% y -1%, para evitar esos porcentajes hacemos un control de valores 
if(waterValue > adc){
  waterValue = adc;  
}


return 100*airValue/(airValue-waterValue)-adc*100/(airValue-waterValue);
}
int SensorHumedad::getWaterValue(){
  return waterValue;
}
//
