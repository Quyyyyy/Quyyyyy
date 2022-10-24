#include <BH1750.h>
#include <Wire.h>

BH1750 lightMeter;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  lightMeter.begin();
  pinMode(13,OUTPUT);

  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  float lux = lightMeter.readLightLevel();

  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
  if(lux < 50){
    digitalWrite(13,HIGH);
  }else digitalWrite(13, LOW);
}
