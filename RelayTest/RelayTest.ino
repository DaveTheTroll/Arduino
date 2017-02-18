void setup()
{
  
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  while (!Serial) {}
}

int loopCount = 0;
void loop()
{
  switch(loopCount%4)
  {
    case 0:
      digitalWrite(9, HIGH);
      break;
    case 1:
      digitalWrite(10, HIGH);
      break;
    case 2:
      digitalWrite(9, LOW);
      break;
    case 3:
      digitalWrite(10, LOW);
      break;
  }

  Serial.println(loopCount);
  
  loopCount++;
  delay(500);
}
