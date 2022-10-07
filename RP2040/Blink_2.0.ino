// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        17 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
#define DELAYCYANON 4000 
#define DELAYCYANOFF 3000
#define DELAYWHITEON 2000

void setup() {

  pinMode(16, OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  digitalWrite(16, HIGH);
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 100, 100));
    pixels.show();
    delay(DELAYCYANON);
    
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(DELAYCYANOFF);

    pixels.setPixelColor(i, pixels.Color(100, 100, 100));
    pixels.show();
    delay(DELAYWHITEON);
    
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(DELAYCYANOFF);
  }
}
