#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"
#include <Keyboard.h>
JOYSTICK joystick; //Create instance of this object

const int led = 9;  
  int brightness = 0;
  
void setup() {
  Serial.begin(9600);
  Serial.println("Qwiic Joystick Example");
  Keyboard.begin();



  if(joystick.begin() == false)
  {
    Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
}

void loop() {
  analogWrite(led, brightness);
    int X = joystick.getHorizontal();
    int Y = joystick.getVertical();
    int B = joystick.getButton();
    
    if  (X > 575)
    {
        Keyboard.write(KEY_LEFT_ARROW);
        //Serial.print("left");
        brightness = 255;
        
    }
    else if (X < 450)
    {
        //Serial.print("right");
        Keyboard.write(KEY_RIGHT_ARROW);
        brightness = 255;
    } else {
      brightness = 0;
      }

    if  (Y > 575)
    {
        //Serial.print("up");
        Keyboard.write(KEY_UP_ARROW);
        brightness = 255;
    }
    else if (Y < 450)
    {
        //Serial.print("down");
        Keyboard.write(KEY_DOWN_ARROW);
        brightness = 255;
    } else {
      brightness = 0;
      }

  delay(200);
}
