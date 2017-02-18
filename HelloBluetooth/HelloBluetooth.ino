#include <SoftwareSerial.h>

SoftwareSerial bt(6, 7);  // Bluetooth serial on pins 6 and 7.
int loopCount = 0;

void setup()
{
  // Open Bluetooth comms 
  bt.begin(9600);
  // Open serial comms
  Serial.begin(9600);
  // Wait for Bluetooth serial to be ready
  while (!bt) {}
  // Wait for serial to be ready
  while (!Serial) {}

  // Request version.  Just to check that comms works.
  bt.print("AT+VERSION?\r\n");
}

void loop()
{
  while (bt.available())
  {
    int btData = bt.read();
    Serial.print(char(btData));
    if (btData == 'H')
      bt.println("Hello Bluetooth"); 
  }
  if ((loopCount % 10) == 0)
  {
    Serial.print('*');
    if ((loopCount % 100) == 0)
    Serial.print('\n');
  } 
  loopCount++;
  delay(100);
}
