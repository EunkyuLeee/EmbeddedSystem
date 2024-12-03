int pid = 7;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(pid, INPUT);
}

void loop() {
  value = digitalRead(pid);
  Serial.println(value);
  delay(1000);
}
