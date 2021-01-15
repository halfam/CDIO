#ifndef SALINIDAD_YA_INCLUIDO
#define SALINIDAD_YA_INCLUIDO

#include <Adafruit_ADS1015.h>

class SensorSalinidad{
  private:    
    int maxValue;
    int minValue;
    Adafruit_ADS1115 direccion;
    int pinADS;
    int pinSalida;
    
  public:
    SensorSalinidad(int,int);
    void setADS(Adafruit_ADS1115);
    int getSalinidad();
};
#endif
