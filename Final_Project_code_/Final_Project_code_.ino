#include <Adafruit_NeoPixel.h>

#define LED_PIN    7 
#define LED_COUNT  15


int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorStartValue = 0;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
//  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();
}

void loop() {
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  Serial.println("sensor 1: " + sensorValue1); 
  delay(10);
  Serial.println("sensor 2: " + sensorValue2); 
  delay(10);
  if (sensorValue1 > 100 || sensorValue2 > 100){
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
  
