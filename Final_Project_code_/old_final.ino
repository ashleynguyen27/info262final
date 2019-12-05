//#include <Adafruit_NeoPixel.h>
//#include "pitches.h"
//#define LED_PIN    10
//#define LED_COUNT  12
//
//int fsrreading = 0; // The current reading from the FSR
//int state = HIGH; // The current state of the output pin
//int previous = 0; // The previous reading from the FSR
//// The follow variables are long's because the time, measured in miliseconds, will quickly become a bigger number than can be stored in an int:
//long time = 0;  // The last time the output pin was toggled
//long debounce = 40; // The debounce time, increase if the output flickers
//
//int fsrPin = A0;
//int speakerPin = 7;
//int hePin1 = 2;
//int heValue1 = 0;
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//
//int MarioUW_note[] = {
//  NOTE_AS3, NOTE_AS4, 0, 0
//};
//int MarioUW_duration[] = {
//12, 12, 6,3
//};
//
//void setup() {
//  Serial.begin(9600);
//  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
//  strip.show();
//}  
//
//void loop(){
//  // Read the FSR pin and store the output as fsrreading:
//  fsrreading = analogRead(fsrPin);
//  heValue1 = digitalRead(hePin1);
//  // Print the fsrreading in the serial monitor:
//  Serial.println(fsrreading);
//  // If the input just went from below 500 to above 500 and we've waited long enough to ignore any noise on the circuit, toggle the output pin and remember the time:
//  if (fsrreading > 500 && previous < 500 && millis() - time > debounce) {
//    if (state == HIGH)
//      state = LOW;
//    else
//      state = HIGH;
//    time = millis();
//  }
//  previous = fsrreading;
//  if (state == HIGH){
//    changeColor(heValue1);
//  } else { 
//    Serial.println("reached");
//    turnStripOff();
//  }
//}
//
//
//
//
//void turnStripOff(){
//  colorWipe(strip.Color(0,   0,   0), 0);
//}
//
//
//void changeColor(int value) {
//  if (value){
//    colorWipe(strip.Color(0,   255,   0), 50);
//  } else { 
//    colorWipe(strip.Color(255,   0,   0), 50);
//  }
//}
//
//void colorWipe(uint32_t color, int wait) {
//  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
//    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
//    strip.show();                          
//  }
//}
//
//void rainbow(int wait) {
//  // Hue of first pixel runs 5 complete loops through the color wheel.
//  // Color wheel has a range of 65536 but it's OK if we roll over, so
//  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
//  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
//  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
//    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
//      // Offset pixel hue by an amount to make one full revolution of the
//      // color wheel (range of 65536) along the length of the strip
//      // (strip.numPixels() steps):
//      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
//      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
//      // optionally add saturation and value (brightness) (each 0 to 255).
//      // Here we're using just the single-argument hue variant. The result
//      // is passed through strip.gamma32() to provide 'truer' colors
//      // before assigning to each pixel:
//      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
//    }
//    strip.show(); // Update strip with new contents
//    delay(wait);  // Pause for a moment
//  }
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//void play_MarioUW() {
//  int MarioUW_note[] = {
//    NOTE_AS3, NOTE_AS4, 0, 0
//  };
//  int MarioUW_duration[] = {
//  12, 12, 6,3
//  };
//  for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {
//
//    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
//    tone(8, MarioUW_note[thisNote], noteDuration);
//  
//    int pauseBetweenNotes = noteDuration * 1.80;
//    delay(pauseBetweenNotes);
//    noTone(speakerPin); //stop music on pin 8 
//  }
//}
