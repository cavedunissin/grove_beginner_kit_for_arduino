//light Induction Desk Lamp
int soundPin = A2; // Analog sound sensor is to be attached to analog
int lightPin = A6; //Analog light sensor is to be attached to analog
int ledPin = 4; // Digital LED is to be attached to digital

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
  pinMode(soundPin, INPUT);
}

void loop() {
  int soundState = analogRead(soundPin); // Read sound sensor’s value
  int lightState = analogRead(lightPin); // Read light sensor’s value
  // if the sound sensor's value is greater than 600 or the light sensor's  is less than 20, the light will be on.
  //Otherwise, the light will be turned off
  if (soundState > 600 || lightState < 20)
  { digitalWrite(ledPin, HIGH);
    //delay(5000); //You can delete the "//" to make the LED on for five seconds
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
