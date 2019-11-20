#include <Adafruit_NeoPixel.h>
#include "pitches.h"
#define LED_PIN    9
#define LED_COUNT  15


//int fsrPin1 = A0;
//int fsrValue1 = 0;
int speakerPin = 7;
int hePin1 = A0, hePin2 = 3, hePin3 = 4, hePin4 = 5;
int heValue1 = 0, heValue2 = 0, heValue3 = 0, heValue4 = 0;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int MarioUW_note[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,NOTE_AS3, NOTE_AS4, 0, 0,
//  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0,0,
//  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,NOTE_DS3, NOTE_DS4, 0, 0,
//  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,NOTE_DS3, NOTE_DS4, 0,
//  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
//  NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4,
//  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
//  NOTE_GS4, NOTE_DS4, NOTE_B3,  NOTE_AS3, NOTE_A3, NOTE_GS3,0, 0, 0
};
int MarioUW_duration[] = {
 12, 12, 12, 12,12, 12, 6,3,
// 12, 12, 12, 12, 12, 12, 6, 3,
// 12, 12, 12, 12, 12, 12, 6,
// 3, 12, 12, 12, 12,
// 12, 12, 6, 6, 18, 18, 18,
// 6, 6, 6, 6,6, 6,
// 18, 18, 18, 18, 18, 18, 10, 10, 10,
// 10, 10, 10, 3, 3, 3
};

// the note the user wants to play that we read from serial
char serNote;

void setup() {
  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();
}

void loop() {
////  fsrValue1 = analogRead(fsrPin1);
  heValue1 = digitalRead(hePin1);
//  heValue2 = digitalRead(hePin2);
//  heValue3 = digitalRead(hePin3);
//  heValue4 = digitalRead(hePin4);
  Serial.println(heValue1); 
//  Serial.println("he sensor 2: " + heValue2); 
//  Serial.println("he sensor 3: " + heValue3); 
//  Serial.println("he sensor 4: " + heValue4); 
  delay(10);
  if (heValue1){
    
  }
  if (heValue1){
    colorWipe(strip.Color(0,   255,   0), 50);
    rainbow(10);
    play_MarioUW();
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

void play_MarioUW() {
    for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
    tone(8, MarioUW_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(speakerPin); //stop music on pin 8 
    }
}
