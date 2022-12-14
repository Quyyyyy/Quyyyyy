#define BLYNK_TEMPLATE_ID           "TMPLBKYdPeg9"
#define BLYNK_DEVICE_NAME           "CHONG TROM"
#define BLYNK_AUTH_TOKEN            "o7QM6QCDA-w4fbWriJGVvCJpGNZGdgpB"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssin[] = "P305";
char pass[] = "hoilamgi";

#define cambien D2
#define buzzer D7

int giatri = 0;

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth,ssin,pass);
  pinMode(cambien,INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);
}

void loop(){
  Blynk.run();
  giatri = digitalRead(cambien);
  if(giatri==1)
  {
    Serial.print("Có người    ");
    digitalWrite(buzzer,HIGH);
    Blynk.virtualWrite(V0,giatri);
  }
  else{
    Serial.print("Không Có người    ");
    digitalWrite(buzzer,LOW);
    Blynk.virtualWrite(V0,giatri);
  }
  Serial.print("Giá trị của cảm biến la: ");
  Serial.println(giatri);
  Serial.println(" ");
}
