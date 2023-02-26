#include "pitches.h"
 
const int threshold = 375;      // minimum reading of the sensors that generates a note
const int speakerPin = 8;      // pin number for the speaker
const int noteDuration = 350;   // play notes for 20 ms
 
// notes to play, corresponding to the 3 sensors:
int notes[] = {
NOTE_A4, NOTE_D4};
 
void setup() {
Serial.begin(9600);    
}
 
void loop() {
  
for (int thisSensor = 0; thisSensor < 1; thisSensor++) {
    // get a sensor reading:
    int sensorReading = analogRead(thisSensor);
 Serial.println(sensorReading);      // print it
    // if the sensor is pressed hard enough:
    if (sensorReading < threshold) {
      // play the note corresponding to this sensor:
      tone(speakerPin, notes[thisSensor], noteDuration);
    }
  }
}
