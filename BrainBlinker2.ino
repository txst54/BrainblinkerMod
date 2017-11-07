#include <Brain.h>
Brain brain(Serial);
const int ledPin = 8; 
long interval = 500; 
long previousMillis = 0;
int ledState = LOW; 
int medValue;
void setup() {
 // Set up the LED pin.
 pinMode(ledPin, OUTPUT);
 
 // Start the hardware serial.
 Serial.begin(9600);
}
void loop() {
 // Expect packets about once per second.
 if (brain.update()) {
 Serial.println(brain.readCSV());
 
 // Attention runs from 0 to 100.
 medValue = brain.readMeditation();
 }
 
 // Make sure we have a signal.
 if(brain.readSignalQuality() == 0) {
 
 // Send a signal to the LED.
 if (medValue < 50) {
 digitalWrite(ledPin, HIGH);
 //delay(10);
 }
 else {
  digitalWrite(ledPin, LOW);
  //delay(10);
  }
 }
 } 
 

