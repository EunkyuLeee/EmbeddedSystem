#include <DHT.h>

int dhtPin = 6;
float humidity, temperature;
int cdsPin = A0;
int cdsValue;
int pidPin = 7;
int pidValue;
int mqPin = A1;
int mqValue;
// int relayPin = 8;


DHT dht(dhtPin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(pidPin, INPUT);
  // pinMode(relayPin, OUTPUT);
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  cdsValue = analogRead(cdsPin);
  pidValue = digitalRead(pidPin);
  mqValue = analogRead(mqPin);

  // if (temperature < 40) {
  //   digitalWrite(relayPin, HIGH);
  // } else {
  //   digitalWrite(relayPin, LOW);
  // }

  // Serial.print("CDS: ");
  // Serial.println(cdsValue);
  // Serial.print("PID: ");
  // Serial.println(pidValue);
  // Serial.print("h, t: ");
  // Serial.print(humidity);
  // Serial.print(", ");
  // Serial.println(temperature);
  // Serial.print("MQ: ");
  // Serial.println(mqValue);

  String id = String(random(0,100));
  String temp = String(temperature);
  String humi = String(humidity);
  String brightness = String(map(cdsValue, 0, 700, 0, 100));
  String co2 = String(mqValue);
  String soil_moisture = String(10);
  String intrusion;
  if (pidValue == 1) {
    intrusion = "\"있음\"";
  } else {
    intrusion = "\"없음\"";
  }

  String jsonPayload = "{\"id\": " + id + 
      ",\"temperature\": " + temperature +
      ",\"humidity\": " + humidity +
      ",\"brightness\": " + brightness +
      ",\"co2\": " + co2 +
      ",\"soil_moisture\": " + soil_moisture +
      ",\"intrusion\": " + intrusion + "}";
  
  Serial.println(jsonPayload);

  delay(1000);
}
