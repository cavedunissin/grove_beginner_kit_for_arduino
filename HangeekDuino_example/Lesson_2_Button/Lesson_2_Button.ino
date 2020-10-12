/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 03:16:08 GMT
 */



void setup()
{
  pinMode(4, OUTPUT);

}


void loop()
{
  if ((digitalRead(6)) == 1) {
    digitalWrite(4, 1);

  } else {
    digitalWrite(4, 0);

  }
}