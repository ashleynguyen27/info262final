int sensorPin = A0; // pin for the fsr
int redledPin = 9;
int blueledPin = 10;
int greenledPin = 11;
int sensorValue = 0; // variable to store the value coming from the sensor
int sensorStartValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redledPin, OUTPUT);
  pinMode(blueledPin, OUTPUT);
  pinMode(greenledPin, OUTPUT);
  sensorStartValue = analogRead(sensorPin); // get the initial value of the sensor
}

void loop() {
  sensorValue = analogRead(sensorPin)
  sensorValue = sensorValue/4; // converts sensor value to ~color value 0-255
  Serial.println(sensorValue); // prints the sensor value so we can see what it is
  
  if (sensorValue + 20 >= sensorStartValue){ // There is no object detected
    redVal = 255;
    greenVal = 0;
  } else if (sensorValue + 20 < sensorValue){ // Second phase of fade
    redVal = sensorValue;
    greenVal = abs(sensorValue - 255);

//    redVal = abs((sensorValue * .75) - 255);
//    greenVal = (sensorValue * 0.75);
  }
  
  analogWrite(redPin, redVal); // Write current values to LED pins
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, 0);
  
  delay(1); // delay in between reads for stability

}
