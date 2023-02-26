#include <Keyboard.h>

int buttonPin[] = {2,3,4,5};
int prevButtonState[] = {HIGH, HIGH, HIGH, HIGH};


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for (int n = 0; n < 4; n++){
    pinMode(buttonPin[n], INPUT);
  }
}

void loop() {
 for (int n = 0; n < 4; n++){
    int buttonState = digitalRead(buttonPin[n]);

    if (buttonState != prevButtonState[n]){
      if (buttonState == LOW){
      sendKey(buttonPin[n]);  

      }
      prevButtonState[n] = buttonState;
    
      }
      }
}

 void sendKey(int thisButton) {

  switch (thisButton) {
    case 2:
      Keyboard.write(KEY_UP_ARROW);
      Serial.println("up");
      break;
    case 3: 
      Keyboard.write(KEY_DOWN_ARROW);
      Serial.println("down");
      break;
    case 4:
      Keyboard.write(KEY_RIGHT_ARROW);
      Serial.println("right");
      break;    
    case 5:
      Keyboard.write(KEY_LEFT_ARROW);
      Serial.println("left");
      break;
  }
  delay(30);
  Keyboard.releaseAll();
} 
