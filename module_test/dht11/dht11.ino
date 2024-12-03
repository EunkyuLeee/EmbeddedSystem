#include <DHT.h>

int sensor = 6;
float humidity, temperature;

DHT dht(sensor, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  Serial.print(humidity);
  Serial.print(", ");
  Serial.println(temperature);
  delay(1000);
}
