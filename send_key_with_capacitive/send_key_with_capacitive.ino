#include <BleKeyboard.h>
#define keyDelay 150

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting!");
  bleKeyboard.begin();
}

void loop() {
  // Serial.println(touchRead(T2));
  // delay(10);
  if (bleKeyboard.isConnected()) {
    // Serial.println("Sending 'Hello world'...");
    // bleKeyboard.print("Hello world");

    // delay(1000);

    // Serial.println("Sending Enter key...");
    // bleKeyboard.write(KEY_RETURN);

    // delay(1000);

    // Serial.println("Sending Play/Pause media key...");
    // bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
    if (touchRead(T2) < 50) {
      bleKeyboard.write(KEY_LEFT_ARROW);
      Serial.println("Sending arrow down");
      delay(keyDelay);
    }
    if (touchRead(T6) < 50) {
      bleKeyboard.write(KEY_UP_ARROW);
      Serial.println("Sending arrow down");
      delay(keyDelay);
    }
    if (touchRead(T5) < 50) {
      bleKeyboard.write(KEY_DOWN_ARROW);
      Serial.println("Sending arrow down");
      delay(keyDelay);
    }
    if (touchRead(T4) < 50) {
      bleKeyboard.write(KEY_RIGHT_ARROW);
      Serial.println("Sending arrow down");
      delay(keyDelay);
    }

    delay(10);

    //
    // Below is an example of pressing multiple keyboard modifiers
    // which by default is commented out.
    //
    /* Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */

  } else {
    Serial.println("Waiting 5 seconds...");
    delay(5000);
  }
}