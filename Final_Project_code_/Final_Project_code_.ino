#include <Adafruit_NeoPixel.h>

#define LED_PIN    7 
#define LED_COUNT  15


int fsrPin1 = A0;
int fsrPin2 = A1;
int hePin1 = 7;
int fsrValue1 = 0;
int fsrValue2 = 0;
int heValue1 = 7;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();
}

void loop() {
  fsrValue1 = analogRead(fsrPin1);
  fsrValue2 = analogRead(fsrPin2);
  heValue1 = digitalRead(hePin1);
  Serial.println("fsr sensor 1: " + fsrValue1); 
  delay(10);
  Serial.println("fsr sensor 2: " + fsrValue2); 
  delay(10);
  Serial.println("he sensor 1: " + heValue1); 
  delay(10);
  if ((fsrValue1 > 100 || fsrValue2 > 100) && heValue1){
    rainbow(0);
  }
  if (fsrValue1 > 100 || fsrValue2 > 100){
    colorWipe(strip.Color(0,   255,   0), 50);
  } else { 
    colorWipe(strip.Color(255,   0,   0), 50);
  }
}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                         
  }
}

void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
  
