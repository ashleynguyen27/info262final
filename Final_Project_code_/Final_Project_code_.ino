#include <Adafruit_NeoPixel.h>

#define LED_PIN    8
#define LED_COUNT  15


//int fsrPin1 = A0;
//int fsrValue1 = 0;
int hePin1 = 2, hePin2 = 3, hePin3 = 4, hePin4 = 5;
int heValue1 = 0, heValue2 = 0, heValue3 = 0, heValue4 = 0;
Adafruit_NeoPixel strip1(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  strip1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip1.show();
  strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();
  strip3.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip3.show();
  strip4.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip4.show();
}

void loop() {
//  fsrValue1 = analogRead(fsrPin1);
  heValue1 = digitalRead(hePin1);
  heValue2 = digitalRead(hePin2);
  heValue3 = digitalRead(hePin3);
  heValue4 = digitalRead(hePin4);
//  Serial.println("he sensor 1: " + heValue1); 
//  Serial.println("he sensor 2: " + heValue2); 
//  Serial.println("he sensor 3: " + heValue3); 
//  Serial.println("he sensor 4: " + heValue4); 
  delay(10);
  if (heValue1 && heValue2 && heValue3 && heValue4){
    rainbow(10);
  }
  if (heValue1){
    colorWipe(strip1.Color(0,   255,   0), 50);
  } else { 
    colorWipe(strip1.Color(255,   0,   0), 50);
  }
  if (heValue2){
    colorWipe(strip1.Color(0,   255,   0), 50);
  } else { 
    colorWipe(strip1.Color(255,   0,   0), 50);
  }
  if (heValue3){
    colorWipe(strip1.Color(0,   255,   0), 50);
  } else { 
    colorWipe(strip1.Color(255,   0,   0), 50);
  }
  if (heValue4){
    colorWipe(strip1.Color(0,   255,   0), 50);
  } else { 
    colorWipe(strip1.Color(255,   0,   0), 50);
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
  for(long firstPixelHue = 0; firstPixelHue < 1*65536; firstPixelHue += 256) {
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
  
