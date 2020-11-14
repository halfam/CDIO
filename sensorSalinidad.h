#define salinity_power_pin 5
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#define pinADS1115sensorSalinidad 0

Adafruit_ADS1115 ads1115(0x48); // construct an ads1115 at address 0x48
void setupSalinidad() {
  Serial.begin(9600);
  ads1115.begin(); //Initialize ads1115
  ads1115.setGain(GAIN_ONE);
  pinMode(salinity_power_pin, OUTPUT);
}

int loopSalinidad() {
  // put your main code here, to run repeatedly:
  int16_t adc0;
  digitalWrite( salinity_power_pin, HIGH);
  delay(1000);
  adc0 = ads1115.readADC_SingleEnded(pinADS1115sensorSalinidad);
  digitalWrite(salinity_power_pin, LOW);
  return map(adc0, 6, 26364, 0, 100);
}
