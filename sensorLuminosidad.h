#include <Adafruit_ADS1015.h>

void setupLuminosidad() {
}
int lecturaLuminosidad(Adafruit_ADS1115 address,int pin_canal_ads) {
  int16_t adc3;
  adc3 = address.readADC_SingleEnded(pin_canal_ads);
  if(adc3 >= 800)
    return 0;
  if(adc3 < 800 and adc3 > 150)
    return 1;
  if(adc3 <= 150)
    return 2; 
}
