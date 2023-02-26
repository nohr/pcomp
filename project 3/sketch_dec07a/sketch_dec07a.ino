#include <Keyboard.h>
#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"
JOYSTICK joystick; //Create instance of this object

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
    int X = joystick.getHorizontal();
    int Y = joystick.getVertical();
    int B = joystick.getButton();
    if  (X > 575)
    {
        //Keyboard.write(KEY_LEFT_ARROW);
        Serial.print('left');
    }
    else if (X < 450)
    {
        Serial.print('right');
        //Keyboard.write(KEY_RIGHT_ARROW);
    }

    if  (Y > 575)
    {
        Serial.print('up');
        //Keyboard.write(KEY_UP_ARROW);
    }
    else if (Y < 450)
    {
        Serial.print('down');
        //Keyboard.write(KEY_DOWN_ARROW);
    }

    if (B == 0)
    {
        Serial.println("Button");
    }


  delay(200);
}
