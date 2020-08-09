//Gravity Acceleration Buzzer
#include "LIS3DHTR.h"
#ifdef SOFTWAREWIRE
#include <SoftwareWire.h>
SoftwareWire myWire(3, 2);
LIS3DHTR<SoftwareWire> LIS;//IIC
#define WIRE myWire
#else
#include <Wire.h>
LIS3DHTR<TwoWire> LIS;//IIC
#define WIRE Wire
#endif
int ledPin =  4;
int buzzerPin = 5;
int buttonPin = 6;
int buttonState = 0;
int buttonPushCounter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  while (!Serial) {};
  LIS.begin(WIRE, 0x19); //IIC init
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (!LIS) {
    Serial.println("LIS3DHTR didn't connect.");
    while (1);
    return;
  }
  //read and display accel sensor 3-axis data
  Serial.print("x:");
  Serial.print(LIS.getAccelerationX());
  Serial.print("  ");
  Serial.print("y:");
  Serial.print(LIS.getAccelerationY());
  Serial.print("  ");
  Serial.print("z:");
  Serial.println(LIS.getAccelerationZ());
  Serial.println(buttonPushCounter);
  delay(500);
  float ax, ay, az;
  ax = LIS.getAccelerationX();
  ay = LIS.getAccelerationY();
  az = LIS.getAccelerationZ();

  if (buttonState == HIGH) {
    buttonPushCounter++;
    // button++:
  }
  if (buttonPushCounter >= 3) {
    noTone(5);    // turn BUZZER off:
  }
  else if ( ax > 0.25 || ay > 0.25 || ax < -0.25 || ay < -0.25 ) {
    tone(5, 1000, 1000); // turn BUZZER on:
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
