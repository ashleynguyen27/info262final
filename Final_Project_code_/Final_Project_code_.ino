#include <FastLED.h>

#define LED_PIN    7 
#define NUM_LEDS  12

CRGB leds[1];

int sensorPin = A0;
int sensorValue = 0;
int sensorStartValue = 0;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); 
  if (sensorValue  > 200){
    for(int i = 0; i < 15; i++){
      leds[i] = CRGB(0, 255, 0);
    }
  } else if (sensorValue <= 100){ 
    for(int j = 0; j < 15; j++){
      leds[j] = CRGB(255, 0, 0);
    }
  }
FastLED.show();
}

  
