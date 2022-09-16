
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h> 

#define BLYNK_AUTH_TOKEN "BLYNK_TOKEN"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SSID";//Enter your WIFI name
char pass[] = "PASSWORD";//Enter your WIFI password

BlynkTimer timer;
int buttonValue = 0;

#define Buzzer D5
#define GreenLed D6
#define BlueLed D7
#define GasSensor A0

void setup() {
  Serial.begin(9600);
  pinMode(GreenLed, OUTPUT);
  pinMode(BlueLed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(GasSensor, INPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(100L, notification);
}
BLYNK_WRITE(V0) {
  buttonValue = param.asInt();
}

void notification() {
  int gasSensor = analogRead(GasSensor);
  Serial.println(gasSensor);
  gasSensor = map(gasSensor, 0, 1024, 0, 100);
  if (buttonValue == 1) {
    if (gasSensor <= 50) {
      digitalWrite(GreenLed, HIGH);
      digitalWrite(BlueLed, LOW);
      digitalWrite(Buzzer, LOW);
    } else if (gasSensor > 50) {
      Blynk.notify("Warning! Gas leak detected");
      digitalWrite(GreenLed, LOW);
      digitalWrite(BlueLed, HIGH);
      digitalWrite(Buzzer, HIGH);
    }

    Blynk.virtualWrite(V1, gasSensor);
  } else {
    digitalWrite(BlueLed, LOW);
    digitalWrite(Buzzer, LOW);
    digitalWrite(GreenLed, LOW);
  }
}

void loop() {
  Blynk.run();
  timer.run();
}
