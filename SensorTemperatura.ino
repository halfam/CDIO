#include <Adafruit_ADS1015.h>
#include <Wire.h>

// El valor de la "otra" resistencia
#define SERIESRESISTOR 2200   
 
// El pin por el cual se conecta el sensor
#define THERMISTORPIN 0

//constante de A
#define CONSTANTE 7999.76
#define B 0.79
#define M 0.035
#define INCREMENTO 0.2045

Adafruit_ADS1115 ads1115(0x48);
 
void setup(void) {
  Serial.begin(9600);
  Serial.println("Inicializando...");
  ads1115.begin();
  Serial.println("Ajustando la ganancia...");
  ads1115.setGain(GAIN_ONE);

  Serial.println("Tomando medidas del canal AIN2");
  Serial.println("Rango del ADC: +/- 4.096V (1 bit=2mV)");
}
 
void loop(void) {
  float reading;
 int16_t adc2;
 
  adc2 = ads1115.readADC_SingleEnded(THERMISTORPIN);
  Serial.println(adc2);
  float A = CONSTANTE * adc2;
  float vo= A /CONSTANTE;
  float temperatura = (((vo - B*CONSTANTE))/(M*CONSTANTE));
  //float temperatura = ((A/CONSTANTE - B) / M);
  Serial.print("Temperatura actual: "); 
  Serial.println(temperatura);
  delay(1000);
}
