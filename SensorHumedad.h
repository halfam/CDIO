#ifndef HUMEDAD_YA_INCLUIDO
#define HUMEDAD_YA_INCLUIDO

#include <Adafruit_ADS1015.h>
class SensorHumedad{
  private:    
    int airValue;
    int waterValue;
    Adafruit_ADS1115 direccion;
    int pinADS;
   
  public:
    SensorHumedad( int);
    void setADS(Adafruit_ADS1115);
    int getPorcentajeHumedad();
    int getAirValue();
    int getWaterValue();
};
#endif
