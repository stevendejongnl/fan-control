// Pin assignments
const int buttonPin = 2;  // Pin for the button
const int relayPin = 3;   // Pin for the relay
const int ledPin = 4;     // Pin for the LED

int duration = 1;  // Current duration of the fans in hours
unsigned long lastButtonPress = 0;  // Timestamp of the last button press

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  checkButtonPress();
  controlFans();
  checkLongPress();
}

void checkButtonPress() {
  if (digitalRead(buttonPin) == LOW) {
    unsigned long buttonPressDuration = millis() - lastButtonPress;

    if (buttonPressDuration < 3000) {
      increaseDuration();
      confirmAction();  // Confirm action with LED blink
      lastButtonPress = millis();
    }
  }
}

void increaseDuration() {
  duration++;
}

void controlFans() {
  if (duration > 0) {
    digitalWrite(relayPin, HIGH);  // Turn on the fans
  } else {
    digitalWrite(relayPin, LOW);   // Turn off the fans
  }
}

void checkLongPress() {
  if (digitalRead(buttonPin) == LOW) {
    unsigned long buttonPressDuration = millis() - lastButtonPress;

    if (buttonPressDuration >= 3000 && buttonPressDuration < 10000) {
      displayRemainingTime();
    } else if (buttonPressDuration >= 10000) {
      turnEverythingOff();
    }
  } else {
    lastButtonPress = millis();
  }
}

void displayRemainingTime() {
  int remainingTime = duration;
  for (int i = 0; i < remainingTime; i++) {
    blinkLed(1);    // Blink the LED once to indicate each hour
    delay(500);
  }
}

void turnEverythingOff() {
  digitalWrite(relayPin, LOW);  // Turn off the fans
  confirmAction();              // Confirm action with LED blink
  duration = 0;                 // Reset the duration
}

void confirmAction() {
  blinkLed(2);  // Blink the LED twice to confirm the action
}

void blinkLed(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}
