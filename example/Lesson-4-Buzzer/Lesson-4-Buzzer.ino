1j2lˋint BuzzerPin = 5;
int Potentiometer = A0;
void setup() {
  pinMode(BuzzerPin, OUTPUT);
}
void loop() {
  int potentioValue, value;
  potentioValue = analogRead(Potentiometer);
  value = map(potentioValue, 0, 1023, 0, 255);
  //Mapping potentiometer value to PWM signal value
  analogWrite(BuzzerPin, value);
}
