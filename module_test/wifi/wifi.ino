#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <string.h>

const char* SSID = "SK_WiFiGIGA1594";
const char* PASSWORD = "1903055488";

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

  String receivedData;

  while (Serial.available()) { // 데이터가 수신되었는지 확인
    receivedData = Serial.readStringUntil('\n'); // 데이터 읽기
    Serial.println("Received: " + receivedData); // 수신된 데이터 출력
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient wifiClient;

    setURL(buf, SERVER, "/getLight");    

    http.begin(wifiClient, buf);

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      // Serial.println(httpResponseCode);
      // Serial.println(payload);
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
      // Serial.println(payload);
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

    http.POST(receivedData);

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
  
  delay(1000);
}

void setURL(char *buf, const char *s, const char *p) {
  memset(buf, 0, sizeof(buf));
  strcpy(buf, s);
  strcat(buf, p);
}