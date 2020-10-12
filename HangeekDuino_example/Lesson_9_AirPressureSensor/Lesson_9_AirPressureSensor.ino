/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 05 Oct 2020 04:19:03 GMT
 */

#include "Seeed_BMP280.h"
#include <Wire.h>;
BMP280 bmp280;

void setup()
{
  bmp280.init();

  Serial.begin(9600);

}


void loop()
{
  Serial.print("Pressure: ");
  Serial.print((bmp280.getPressure()));
  Serial.println("Pa");
  Serial.print("Altitude: ");
  Serial.print((bmp280.calcAltitude(bmp280.getPressure())));
  Serial.println("m");
  Serial.println("");
  delay(1000);
}