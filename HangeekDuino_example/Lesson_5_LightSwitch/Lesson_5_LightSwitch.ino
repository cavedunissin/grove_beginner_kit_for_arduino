/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 28 Sep 2020 04:48:13 GMT
 */



int Value;

void setup()
{
  pinMode(4, OUTPUT);

  Serial.begin(9600);

}


void loop()
{
  Value = (map(analogRead(6),0,1023,0,255));
  Serial.println((analogRead(6)));
  digitalWrite(4, null);
}