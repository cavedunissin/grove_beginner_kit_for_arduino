/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 04:13:11 GMT
 */



int Value;

void setup()
{
  pinMode(5, OUTPUT);

}


void loop()
{
  Value = (map(analogRead(0),0,1023,0,255));
  analogWrite(5, Value);
}