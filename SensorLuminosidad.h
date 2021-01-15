#ifndef LUMINOSIDAD_YA_INCLUIDO
#define LUMINOSIDAD_YA_INCLUIDO

#include <Adafruit_ADS1015.h>

class SensorLuminosidad{
  private:    
    int maxValue;
    int minValue;
    Adafruit_ADS1115 direccion;
    int pinADS;
    
  public:
    SensorLuminosidad(int);
    void setADS(Adafruit_ADS1115);
    int getLuminosidad();
};
#endif
