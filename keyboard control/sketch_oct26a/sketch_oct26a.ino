#include <Keyboard.h>

int buttonPin[] = {2,3,4,5};
int prevButtonState[] = {HIGH, HIGH, HIGH, HIGH};
int platform = 0;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  for (int n = 0; n < 4; n++){
    pinMode(buttonPin[n], INPUT);
  }
}

void loop() {

 for (int n = 1; n < 5; n++){
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
    case 2: // A:  Mute/unmute audio
      Keyboard.press('F');
      break;
    case 3: // V: Start/stop video
      Keyboard.press('N');
      break;
    case 4: // N: Switch camera
      Keyboard.press('V');
      break;    
    case 5: // A:  Mute/unmute audio
      Keyboard.press('H');
      break;
  }
  delay(30);
  Keyboard.releaseAll();
} 
