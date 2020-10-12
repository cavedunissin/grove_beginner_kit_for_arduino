/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 06:37:40 GMT
 */



void setup()
{
  pinMode(4, OUTPUT);

  Serial.begin(9600);

}


void loop()
{
  Serial.println((analogRead(2)));
  if ((analogRead(2)) > 600) {
    digitalWrite(4, 1);
    delay(100);

  } else {
    digitalWrite(4, 0);

  }
}