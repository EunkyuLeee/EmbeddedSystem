#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <string.h>
#include <Servo.h>

const char* SSID = "EKPhone";
const char* PASSWORD = "20020903";

const char* SERVER = "http://es7.kro.kr:8080";

Servo windowServo;
int windowPin = 13;

void setup() {

  Serial.begin(9600);

  windowServo.attach(windowPin);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);

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
      int mapping = map(light, 0, 100, 0, 255);
      analogWrite(5, mapping);
      analogWrite(4, mapping);
      analogWrite(0, mapping);
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
      if (strcmp(window, "열림") == 0) {
        windowServo.write(180);
      } else {
        windowServo.write(0);
      }
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