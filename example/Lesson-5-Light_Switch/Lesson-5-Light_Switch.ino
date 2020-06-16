// Light Switch 
int sensorpin = A6; // Analog input pin that the sensor is attached to 
int ledPin = 4;    // LED port 
int sensorValue = 0;  // value read from the port 
int outputValue = 0;  // value output to the PWM (analog out) 
void setup() { 
  pinMode(ledPin,OUTPUT); 
  Serial.begin(9600); 
} 
void loop() { 
  sensorValue = analogRead(sensorpin);      // read the analog in value: 
  outputValue = map(sensorValue, 0, 1023, 0, 255); // map it to the range of the analog out:
  Serial.println(sensorValue);   // change the analog out value:   
analogWrite(ledPin,255-outputValue); 
delay(30); 
} 
