#include <Adafruit_NeoPixel.h>
#include "pitches.h"
#define LED_PIN    10
#define LED_COUNT  24

int fsrreading = 0; // The current reading from the FSR
int state = HIGH; // The current state of the output pin
int previous = 0; // The previous reading from the FSR
// The follow variables are long's because the time, measured in miliseconds, will quickly become a bigger number than can be stored in an int:
long time = 0;  // The last time the output pin was toggled
long debounce = 40; // The debounce time, increase if the output flickers

int fsrPin = A0;
int speakerPin = 8;
int hePin1 = 2, hePin2 = 3, hePin3 = 4, hePin4 = 5;
int heValue1 = 0, heValue2 = 0, heValue3 = 0, heValue4 = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};

//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


void setup() {
  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();
}  

void loop(){
  // Read the FSR pin and store the output as fsrreading:
  fsrreading = analogRead(fsrPin);
  heValue1 = digitalRead(hePin1);
  heValue2 = digitalRead(hePin2);
  heValue3 = digitalRead(hePin3);
  heValue4 = digitalRead(hePin4);
  // Print the fsrreading in the serial monitor:
  Serial.println(fsrreading);
  // If the input just went from below 500 to above 500 and we've waited long enough to ignore any noise on the circuit, toggle the output pin and remember the time:
  if (fsrreading > 500 && previous < 500 && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
    time = millis();
  }
  previous = fsrreading;
  if (state == HIGH){
    changeColor();
  } else { 
    Serial.println("reached");
    turnStripOff();
//    turnStripOff1();
  }
}




void turnStripOff(){
  colorWipe1(strip.Color(0,   0,   0), 0);
  colorWipe2(strip.Color(0,   0,   0), 0);
  colorWipe3(strip.Color(0,   0,   0), 0);
  colorWipe4(strip.Color(0,   0,   0), 0);
}


void changeColor() {
  if (heValue1 && heValue2 && heValue3 && heValue4){
    rainbow(5);
    play_MarioUW();
  }
  if (heValue1){
    colorWipe1(strip.Color(0,   255,   0), 50);
  } else { 
    colorWipe1(strip.Color(255,   0,   0), 50);
  }
  
  if (heValue2){
    colorWipe2(strip.Color(0,   255,   0), 50);
  } else { 
    colorWipe2(strip.Color(255,   0,   0), 50);
  }

  if (heValue3){
    colorWipe3(strip.Color(0,   255,   0), 50);
  } else { 
    colorWipe3(strip.Color(255,   0,   0), 50);
  }
  
  if (heValue4){
    colorWipe4(strip.Color(0,   255,   0), 50);
  } else {
    colorWipe4(strip.Color(255,   0,   0), 50);
  }
}

void colorWipe1(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          
  }
}

void colorWipe2(uint32_t color, int wait) {
  for(int i=6; i<strip.numPixels() + 6; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          
  }
}

void colorWipe3(uint32_t color, int wait) {
  for(int i=12; i<strip.numPixels() + 12; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          
  }
}

void colorWipe4(uint32_t color, int wait) {
  for(int i=18; i<strip.numPixels() + 18; i++) { // For each pixel in strip...
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
  for (int thisNote = 0; thisNote < (sizeof(melody)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / tempo[thisNote];//convert duration to time delay
    tone(8, melody[thisNote], noteDuration);
  
    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(speakerPin); //stop music on pin 8 
  }
}
