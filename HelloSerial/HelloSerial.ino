const char * hello = "Hello World!\n\x07";
int i = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {}
}

void loop()
{
  if (i < strlen(hello))
  {
    Serial.print(hello[i]);
  }
  else if ((i%12)==0)
  {
    Serial.print("\n");
  }
  else
  {
    Serial.print('.');
  }
  i++;
  delay(500);
}
