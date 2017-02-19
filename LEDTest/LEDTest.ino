
#include <Adafruit_NeoPixel.h>
#include "HSVtoRGB.h"

#define PIN (6)
#define LED_COUNT (8)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  
  strip.begin();
  strip.setBrightness(40);
  strip.show();
  
  while(!Serial) {}
}

int iLoop = 0;
void loop()
{
  byte r,g,b;
  HSV_to_RGB((iLoop*5)%360, 100, 30, &r, &g, &b);

  Serial.println(String(iLoop%360) + ":(" + String(r) + "," + String(g) + "," + String(b) + ")");
  
  strip.setPixelColor(iLoop%LED_COUNT, strip.Color(r,g,b));
  strip.setPixelColor((iLoop + LED_COUNT - 1)%LED_COUNT, strip.Color(0,0,0));
  strip.show();
  iLoop++;
  delay(150);
}
