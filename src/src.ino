/*
 * ICST-Button - a buttot that decteds ice axe hits in ice climbing competition

  This sketch reads a piezo element to detect a hig by ice axe and it respons with sound
  and it controls relay to give timing events into the timing system in ice climbing competition.

  The circuit:

  Detecting the ice axe
  - positive connection of the piezo attached to analog in 0
  - negative connection of the piezo attached to ground
  - 1 megohm resistor attached from analog in 0 to ground

  Play sound with PWM via toneAC
    - spekaer connected to the 9 and 10 pins
    - 1M resistor to protect the gates of arduino

  Controlling the releay
    
*/

#include <toneAC.h>

// these constants won't change:
const int ledPin = 13;      // LED connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

int frequency = 2000;

void playSound() {
  toneAC(frequency);
  delay(500);
  toneAC(0);
}

void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    playSound();
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}
