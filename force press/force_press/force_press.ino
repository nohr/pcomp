
const int ledGreen = 9;       // pin that the LED is attached to
const int ledWhite = 6;
int analogValue = 0;        // value read from the pot
int brightness = 0;         // PWM pin that the LED is on.

void setup() {  
// initialize serial communications at 9600 bps:
    Serial.begin(9600);
    // declare the led pin as an output:
    pinMode(ledGreen, OUTPUT);
    pinMode(ledWhite, OUTPUT);
}
void loop() {
analogValue = analogRead(A0);    // read the pot value
    brightness = analogValue /4;       //divide by 4 to fit in a byte
    if (brightness >= 70){
    analogWrite(ledGreen, brightness);   // PWM the LED with the brightness value
    }else if (brightness <= 70){
      analogWrite(ledWhite, brightness);
      }
    Serial.println(brightness);        // print the brightness value back to the serial monitor
}
