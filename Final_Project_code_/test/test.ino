#include <Adafruit_NeoPixel.h>


//define NeoPixel Pin and Number of LEDs
#define PIN 7
#define NUM_LEDS 23
//create a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);


int sensorPin = A0; // pin for the fsr
int sensorValue = 0; // variable to store the value coming from the sensor
int sensorStartValue = 0;


void setup() {
  // start the strip and blank it out
  Serial.begin(9600);
  strip.begin();
  sensorStartValue = analogRead(sensorPin); // get the initial value of the sensor
}

void loop() {
  Serial.println(sensorValue);
  // set pixel to red, delay(1000)
  if (sensorValue - 20 > sensorStartValue){
    strip.setPixelColor(0, 255, 0, 0);
    strip.show();
  } else if (sensorValue - 20 <= sensorStartValue){
  // set pixel to off, delay(1000)
    strip.setPixelColor(255, 0, 0, 0);
    strip.show();
  }
}
