int sensor = A0;
int value;

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  pinMode(sensor, INPUT);
}

void loop() {
  value = analogRead(sensor);
  Serial.println(value);
  delay(1000); // 1초 대기
}