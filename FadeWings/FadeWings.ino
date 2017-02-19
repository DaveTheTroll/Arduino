//Random Flash animation for Neopixel circuits
//by Dano Wall and Becky Stern for Adafruit Industries
//based on the Sparkle Skirt, minus the accelerometer
#include <Adafruit_NeoPixel.h>

#define PIN (6)
#define LED_COUNT (8)
#define ACTIVE_LEDS (8)
#define STEPS_PER_CHANGE (50)
#define MS_PER_STEP (40)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

// Here is where you can put in your favorite colors that will appear!
// just add new {nnn, nnn, nnn}, lines. They will be picked out randomly
//                          R   G   B
/*uint8_t myColors[][6] = {{255, 153, 00},   // bright orange
                         {255, 051, 00},   // orange
						 {204, 00, 051},   // darkred
						 {255, 00, 00},   // red
						 {255, 00, 153},   // brightpink
						 {255, 00, 255},   // pink
                          };*/

class TrollColor
{
public:
	uint8_t R, G, B;

	TrollColor(uint8_t r, uint8_t g, uint8_t b) : R(r), G(g), B(b) {}
};

TrollColor C_RED(255, 0, 0);
TrollColor C_ORANGE(255, 51, 0);
TrollColor C_DARK_RED(204, 0, 51);
TrollColor C_BRIGHT_PINK(255, 0, 153);
TrollColor C_PINK(255, 0, 255);
TrollColor C_BRIGHT_ORANGE(255, 153, 0);

TrollColor C_BLUE(0, 0, 255);

#define COLOR_COUNT (6)
TrollColor colorList[COLOR_COUNT] = {C_RED, C_BRIGHT_ORANGE, C_ORANGE,
				C_DARK_RED, C_BRIGHT_PINK, C_PINK};

int ledColor[LED_COUNT];
int ledNextColor[LED_COUNT];

// don't edit the line below

void setup() {
  Serial.begin(9600);
  
  for(int led = 0; led < LED_COUNT; led++) {
	  ledColor[led] = 0;
  }
  strip.begin();
  strip.setBrightness(40);
  strip.show(); // Initialize all pixels to 'off'

  while (!Serial) {}
  Serial.println("Ready");
}

void nextColor() {
	  for(int led = 0; led < ACTIVE_LEDS; led++) {
		  ledNextColor[led] = random(COLOR_COUNT);
      Serial.print(String(ledNextColor[led], HEX));
      Serial.print(":");
	  }
   Serial.print("\r\n");
}

bool on = false;
void fade() {
	for(int step = 0; step < STEPS_PER_CHANGE; step++) {
		  for(int led = 0; led < ACTIVE_LEDS; led++) {
			  TrollColor & prev = colorList[ledColor[led]];
			  TrollColor & next = colorList[ledNextColor[led]];

			int r = (next.R - prev.R) * step / STEPS_PER_CHANGE + prev.R;
			int g = (next.G - prev.G) * step / STEPS_PER_CHANGE + prev.G;
			int b = (next.B - prev.B) * step / STEPS_PER_CHANGE + prev.B;

			strip.setPixelColor(led, strip.Color(r, g, b));
		  }

		strip.show();
		delay(MS_PER_STEP);
	}
//	strip.setPixelColor(7, strip.Color(on ? 255:0, on?0:255, 0));
//	on = !on;
}
void store() {
	  for(int led = 0; led < ACTIVE_LEDS; led++) {
		ledColor[led] = ledNextColor[led];
	  }
}
void loop() {
	nextColor();
	fade();
	store();
}
