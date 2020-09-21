#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R2, /* reset=*/U8X8_PIN_NONE);
char buzzer = 5;
char button = 6;
char rotary = A0;
char MODE = 1;

void setup() {
  pinMode(rotary, INPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  u8g2.begin();
}

void loop() {


  while (1)
  {
    int n = analogRead(rotary) / 256 + 1;
    select_mode(n);

    if (digitalRead(button) == HIGH)
    {
      MODE = analogRead(rotary) / 256 + 1;
      break;
    }

  }


  if (MODE == 1) {
    Ambulance_show();
  } else if (MODE == 2) {
    Fire_show();
  } else if (MODE == 3) {
    Phone_show();
  } else if (MODE == 4) {
    Start_show();
  }
}

void select_mode(int n)
{
  switch (n)
  {
    case 1:
      u8g2.firstPage();
      do {
        u8g2.setFont(u8g2_font_t0_22b_tf);
        u8g2.setCursor(15, 32);
        u8g2.print("Ambulance"); // write something to the internal memory
      } while (u8g2.nextPage());
      break;
    case 2:
      u8g2.firstPage();
      do {
        u8g2.setFont(u8g2_font_maniac_tf);
        u8g2.setCursor(35, 32);
        u8g2.print("Fire"); // write something to the internal memory
      } while (u8g2.nextPage());
      break;
    case 3:
      u8g2.firstPage();
      do {
        u8g2.setFont(u8g2_font_maniac_tf);//
        u8g2.setCursor(20, 32);
        u8g2.print("Phone"); // write something to the internal memory
      } while (u8g2.nextPage());
      break;
    case 4:
      u8g2.firstPage();
      do {
        u8g2.setFont(u8g2_font_logisoso32_tf);
        u8g2.setCursor(20, 32);
        u8g2.print("Start"); // write something to the internal memory
      } while (u8g2.nextPage());
      break;
  }
}
