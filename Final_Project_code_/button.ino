//// bytes are half the size of int's, but restricted to a max value of 255
//#include <Adafruit_NeoPixel.h>
//#define LED_PIN    10
//#define LED_COUNT  6
//byte button;
//byte oldbutton = 0;
//byte buttonpin = 7;
//byte state = 0;
//Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//
//void setup()
//{
//  pinMode(buttonpin, INPUT);
//  pinMode(12, OUTPUT);
//  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
//  strip.show();
//}
//
//
//void loop()
//{
//  button = digitalRead(buttonpin);
//  if(button && !oldbutton) // same as if(button == high && oldbutton == low)
//  {
//    //we have a new button press
//    if(state == 0) // if the state is off, turn it on
//    {
//      digitalWrite(12, HIGH);
//      state = 1;
//      colorWipe(strip.Color(255,   0,   0), 50);
//    }
//    else // if the state is on, turn it off
//    {
//      digitalWrite(12, LOW);
//      state = 0;
//      colorWipe(strip.Color(0,   255,   0), 50);
//    }
//    oldbutton = 1;
//  }
//  else if(!button && oldbutton) // same as if(button == low && oldbutton == high)
//  {
//    // the button was released
//    oldbutton = 0;
//  }
//}
//
//void colorWipe(uint32_t color, int wait) {
//  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
//    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
//    strip.show();                         
//  }
//}
