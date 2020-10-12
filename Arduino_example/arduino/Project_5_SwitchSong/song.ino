
void Ambulance_show()
{
  for (int i = 0; i < 5; i++) { //repeat 5 times
    tone(5, 400);
    delay(500);
    tone(5, 800);
    delay(500);
    noTone(5);
  }
}

void Fire_show()
{
  for (int i = 700; i < 1500; i += 20) { //upward tone
    tone(5, i);
    delay(37.5);
  }
  for (int i = 1500; i > 700; i -= 20) { //downward tone
    tone(5, i);
    delay(87.5);
  }
  noTone(5);
}
void Phone_show()
{
  for (int i = 0; i < 10; i++) { //repeat 10 times
    tone(5, 2000);
    delay(50);
    tone(5, 1000);
    delay(50);
  }
  noTone(5);
}
void Start_show()
{

}
