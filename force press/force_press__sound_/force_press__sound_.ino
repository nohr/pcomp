
const int speakerPin = 9;       // pin that the speaker is attached to
int analogValue = 0;        // value read from the pot
int brightness = 0;         // PWM pin that the LED is on.
int frequency = 0;

void setup() {  
// initialize serial communications at 9600 bps:
    Serial.begin(9600);
    // declare the speaker pin as an output:
    pinMode(speakerPin, OUTPUT);
}
void loop() {
    analogValue = analogRead(A0);      // read the pot value
    frequency = (analogValue /4) * 10; // divide by 4 to fit in a byte, multiply by 10 for a good tonal range
    tone(speakerPin, frequency);        // make a changing tone on the speaker
    Serial.println(frequency);        // print the brightness value back to the serial monitor
}
