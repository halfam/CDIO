#ifndef TEMPERATURA_YA_INCLUIDO
#define TEMPERATURA_YA_INCLUIDO

#include <Adafruit_ADS1015.h>

class SensorTemperatura{
  private:    
    int maxValue;
    int minValue;
    Adafruit_ADS1115 direccion;
    int pinADS;
    
  public:
    SensorTemperatura(int);
    void setADS(Adafruit_ADS1115);
    int getTemperatura();
};
#endif
