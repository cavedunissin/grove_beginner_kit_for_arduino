//Gravity Acceleration Direction recognizer
#include <Arduino.h>
#include <U8x8lib.h>
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
//Gravity Acceleration
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
int buzzerPin = 5;

void setup() {
  Serial.begin(9600);
  u8x8.begin();
  u8x8.setFlipMode(1);
  pinMode(buzzerPin, OUTPUT);

  while (!Serial) {};
  LIS.begin(WIRE, 0x19); //IIC init
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
}
void loop() {
  if (!LIS) {
    Serial.println("LIS3DHTR didn't connect.");
    while (1);
    return;
  }
  //3 axis
  Serial.print("x:");
  Serial.print(LIS.getAccelerationX());
  Serial.print("  ");
  Serial.print("y:");
  Serial.print(LIS.getAccelerationY());
  Serial.print("  ");
  Serial.print("z:");
  Serial.println(LIS.getAccelerationZ());
  delay(500);

  float ax, ay, az;
  ax = LIS.getAccelerationX();
  ay = LIS.getAccelerationY();
  az = LIS.getAccelerationZ();

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(5, 1);
  u8x8.print("START!");
  delay(500);
  u8x8.clear();

  if ( ax > 0.5) {
    u8x8.setCursor(5, 0);
    u8x8.print("FORWARD!");
    tone(5, 1000, 1000);
    delay(1000);
    u8x8.clear();
  }
  else if (ax < -0.5) {
    u8x8.setCursor(5, 3);
    u8x8.print("BACK!");
    tone(5, 1000, 1000);
    delay(1000);
    u8x8.clear();
  }
  else if (ay > 0.5) {
    u8x8.setCursor(0, 1);
    u8x8.print("LEFT!");
    tone(5, 1000, 1000);
    delay(1000);
    u8x8.clear();
  }
  else if (ay < -0.5) {
    u8x8.setCursor(10, 1);
    u8x8.print("RIGHT!");
    tone(5, 1000, 1000);
    delay(1000);
    u8x8.clear();
  }
}
