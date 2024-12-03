#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <string.h>

const char* SSID = "EKPhone";
const char* PASSWORD = "20020903";

const char* SERVER = "http://es7.kro.kr:8080";

void setup() {

  Serial.begin(9600);

  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting");
  }
  Serial.println("Connected");

  randomSeed(analogRead(A0));

}

void loop() {
  char buf[1024];
  int light;
  char window[10];
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient wifiClient;

    setURL(buf, SERVER, "/getLight");    

    http.begin(wifiClient, buf);

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      // Serial.println(httpResponseCode);
      Serial.println(payload);
      light = atoi(payload.c_str());
      Serial.println(light);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();

    setURL(buf, SERVER, "/getWindow");

    http.begin(wifiClient, buf);

    httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      // Serial.println(httpResponseCode);
      Serial.println(payload);
      strcpy(window, payload.c_str());
      Serial.println(window);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();

    setURL(buf, SERVER, "/addData");

    http.begin(wifiClient, buf);
    http.addHeader("Content-Type", "application/json");
    
    String id = String(random(0,100));
    String temperature = String(20);
    String humidity = String(25);
    String brightness = String(100);
    String co2 = String(10);
    String soil_moisture = String(10);
    String intrusion = "\"없음\"";

    String jsonPayload = "{\"id\": " + id + 
      ",\"temperature\": " + temperature +
      ",\"humidity\": " + humidity +
      ",\"brightness\": " + brightness +
      ",\"co2\": " + co2 +
      ",\"soil_moisture\": " + soil_moisture +
      ",\"intrusion\": " + intrusion + "}";

    http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      String payload = http.getString();
      // Serial.println(httpResponseCode);
      Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  
  delay(10000);
}

void setURL(char *buf, const char *s, const char *p) {
  memset(buf, 0, sizeof(buf));
  strcpy(buf, s);
  strcat(buf, p);
}