//Lesson-10 Gravity Acceleration
//CAVEDU Education 2020
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

void setup() {
  Serial.begin(9600);
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
  //read and display accel sensor 3-axis data 
  Serial.print("x:");
  Serial.print(LIS.getAccelerationX());
  Serial.print("  ");
  Serial.print("y:");
  Serial.print(LIS.getAccelerationY());
  Serial.print("  ");
  Serial.print("z:");
  Serial.println(LIS.getAccelerationZ());
  delay(500);
}
