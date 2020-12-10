#include <Wire.h>
#include <Adafruit_ADS1015.h>

const int AirValue = 30360;  // Medimos valor en seco (calibrado)
int WaterValue = 17705;  // Medimos valor en agua (calibrado)

void setupHumedad() {
  //TODO
  Serial.begin(9600);
  //sacar media de valores del sensor y calibrarlos
}

int leerHumedad(Adafruit_ADS1115 address,int pin_canal_ads) {
//inicialitzacion variables
int16_t adc0;
int16_t humedad;
adc0 = address.readADC_SingleEnded(pin_canal_ads);
//Serial.println(adc0);
//
//la calibración tiene un 99% de precision por lo que los valores de porcentaje muestran
//unos extremos de 101% y -1%, para evitar esos porcentajes hacemos un control de valores 
if(WaterValue > adc0){
  WaterValue = adc0;
  
}


humedad = 100*AirValue/(AirValue-WaterValue)-adc0*100/(AirValue-WaterValue);

//

return humedad;
}

//
