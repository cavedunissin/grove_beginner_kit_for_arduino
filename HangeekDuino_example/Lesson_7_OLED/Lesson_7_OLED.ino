/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 08:45:25 GMT
 */

#include <Arduino.h>
#include <U8x8lib.h>
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup()
{
  u8x8.begin();
  u8x8.setFlipMode(1);u8x8.setFont(u8x8_font_chroma48medium8_r);

}


void loop()
{
  u8x8.setCursor(0, 0);
  u8x8.print("Hello World!");
}