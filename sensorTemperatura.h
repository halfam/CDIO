#include <Adafruit_ADS1015.h>
#include <Wire.h>

// El valor de la "otra" resistencia
#define SERIESRESISTOR 2200
 
// El pin por el cual se conecta el sensor

//constantes de operaciones
#define CONSTANTE 7999.76
#define B 0.79
#define M 0.035
//#define INCREMENTO 0.2045
 
void setupTemperatura(void) {
}
 
float leerTemperatura(Adafruit_ADS1115 address,int pin_canal_ads) {
  int16_t adc2;
  adc2 = address.readADC_SingleEnded(pin_canal_ads);
  float a = CONSTANTE * adc2; 
  float vo= a /CONSTANTE; //voltaje que leemos despues de pasar por la resistencia del ntc
  float temperatura = (vo - B*CONSTANTE)/(M*CONSTANTE);//obtenemos la temperatura a partir de la formula sacada anteriormente
  return temperatura;
}

//Programa realizado por Roberto Matilla, Álvaro Fernández, Joan Altur, Jordi Domenech.
