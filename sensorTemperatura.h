#include <Adafruit_ADS1015.h>
#include <Wire.h>

// El valor de la "otra" resistencia
#define SERIESRESISTOR 2200
 
// El pin por el cual se conecta el sensor
#define PIN_ADS1115_SENSOR_TEMPERATURA 2

//constantes de operaciones
#define CONSTANTE 7999.76
#define B 0.79
#define M 0.035
//#define INCREMENTO 0.2045
 
void setupTemperatura(void) {
  Serial.begin(9600);
  ads1115.begin();
  ads1115.setGain(GAIN_ONE);
}
 
void loopTemperatura(void) {
  int16_t adc2;
  adc2 = ads1115.readADC_SingleEnded(PIN_ADS1115_SENSOR_TEMPERATURA);
  float a = CONSTANTE * adc2; 
  float vo= a /CONSTANTE; //voltaje que leemos despues de pasar por la resistencia del ntc
  float temperatura = (vo - B*CONSTANTE)/(M*CONSTANTE);//obtenemos la temperatura a partir de la formula sacada anteriormente
  return temperatura;
}

//Programa realizado por Roberto Matilla, Álvaro Fernández, Joan Altur, Jordi Domenech.
