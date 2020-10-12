/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 10:14:29 GMT
 */

#include "LIS3DHTR.h"
#include <Wire.h>
LIS3DHTR<TwoWire> LIS(I2C_MODE);
#define WIRE Wire

void setup()
{
  LIS.begin(WIRE, 0x19);
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);

  Serial.begin(9600);

}


void loop()
{
  Serial.print("X:");
  Serial.print((LIS.getAccelerationX()));
  Serial.print(" ");
  Serial.print("Y:");
  Serial.print((LIS.getAccelerationY()));
  Serial.print(" ");
  Serial.print("Z:");
  Serial.println((LIS.getAccelerationZ()));
  delay(1000);
}