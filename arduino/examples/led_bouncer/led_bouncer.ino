#include <Adafruit_NeoPixel.h>

#define PIN 13
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel ambilightstrip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

/* 
The Adafruit_NeoPixel class contains the following methods and variable
  void
    begin(void),
    show(void),
    setPin(uint8_t p),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    setBrightness(uint8_t);
  uint8_t
   *getPixels() const;
  uint16_t
    numPixels(void) const;
  static uint32_t
    Color(uint8_t r, uint8_t g, uint8_t b);
  uint32_t
    getPixelColor(uint16_t n) const;

 */

void setup() {
  ambilightstrip.begin();
  ambilightstrip.show(); // Initialize all pixels to 'off'
}

void loop() {
  static uint8_t r,g,b;
  static int going_up = 0;

  for(int i=0; i< ambilightstrip.numPixels(); i++) {
    ambilightstrip.setPixelColor(i, ambilightstrip.Color(r, g, b));
  }

  if(going_up) {
    r++;
    g++;
    b++;
    if(r == 0xff) {
      going_up = 0;
    }
  } else {
    r--;
    g--;
    b--;
    if(r == 0) {
      going_up = 1;
    }
  }

  ambilightstrip.show();
  //delay(5);
}


