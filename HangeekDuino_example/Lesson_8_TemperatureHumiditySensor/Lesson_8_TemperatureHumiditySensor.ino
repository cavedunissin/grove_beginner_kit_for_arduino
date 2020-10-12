/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 09:13:43 GMT
 */

#include "DHT.h"
DHT dht11_p3(3, DHT11);

#include <Arduino.h>
#include <U8x8lib.h>
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

float temp;

float humi;

void setup()
{
  u8x8.begin();
  u8x8.setFlipMode(1);u8x8.setFont(u8x8_font_chroma48medium8_r);

}


void loop()
{
  temp = (dht11_p3.readTemperature());
  humi = (dht11_p3.readHumidity());
  u8x8.setCursor(0, 33);
  u8x8.print(String() + "Temp:" + temp + "C");
  u8x8.setCursor(0, 50);
  u8x8.print(String() + "Humi:" + humi + "%");
  delay(200);
}