//Lesson-3 Rotary controls LED
//CAVEDU Education 2020

int rotaryPin = A0;    // select the input pin for the rotary
int ledPin = 4;      // select the pin for the LED
int rotaryValue = 0;  // variable to store the value coming from the rota ry

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}
void loop() {
  rotaryValue = analogRead(rotaryPin);   // read the value from the sensor:
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(rotaryValue);   // stop the program for <sensorValue> milliseconds:
  digitalWrite(ledPin, LOW); // turn the ledPin off:
  delay(rotaryValue);
}
