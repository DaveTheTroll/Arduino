
#include <Adafruit_NeoPixel.h>
#include "HSVtoRGB.h"

#define PIN (6)
#define LED_COUNT (8)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void rainbow(int offset)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    byte r,g,b;
    HSV_to_RGB(((i+offset)*360/LED_COUNT)%360, 100, 30, &r, &g, &b);
    strip.setPixelColor(i, strip.Color(r,g,b));
  }
  strip.show();
}

void setup()
{
  Serial.begin(9600);
  
  strip.begin();
  strip.setBrightness(10);
  strip.show();
  
  while(!Serial) {}
  
  strip.show();
}

int iLoop = 0;
void loop()
{
  Serial.println(String(iLoop));
  rainbow(iLoop);
  iLoop++;
  delay(150);
}
