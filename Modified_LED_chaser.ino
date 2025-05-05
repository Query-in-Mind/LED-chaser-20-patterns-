const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // 10 LED pins
const int numLEDs = 10;
const int buttonPin = 12;

int currentPattern = 0;
const int totalPatterns = 20;
bool lastButtonState = HIGH;
bool buttonPressed = false;

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  checkButton();
  runPattern(currentPattern);
}

void checkButton() {
  bool currentState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && currentState == LOW) {
    delay(50); // debounce
    if (digitalRead(buttonPin) == LOW) {
      currentPattern = (currentPattern + 1) % totalPatterns;
      clearLEDs();
    }
  }
  lastButtonState = currentState;
}

void clearLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void runPattern(int pattern) {
  switch (pattern) {
    case 0:
      singleChase();
      break;
    case 1:
      reverseChase();
      break;
    case 2:
      pingPong();
      break;
    case 3:
      twoOpposite();
      break;
    case 4:
      fillFromStart();
      break;
    case 5:
      fillFromEnd();
      break;
    case 6:
      blinkAll();
      break;
    case 7:
      alternateEvenOdd();
      break;
    case 8:
      middleOut();
      break;
    case 9:
      edgesIn();
      break;
    case 10:
      shiftLeft();
      break;
    case 11:
      shiftRight();
      break;
    case 12:
      snakeForward();
      break;
    case 13:
      snakeBackward();
      break;
    case 14:
      flashOneByOne();
      break;
    case 15:
      doubleBounce();
      break;
    case 16:
      rollingPair();
      break;
    case 17:
      fillAndEmpty();
      break;
    case 18:
      randomBlink();
      break;
    case 19:
      runningWave();
      break;
  }
}

// ----- Pattern Functions -----

void singleChase() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void reverseChase() {
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void pingPong() {
  singleChase();
  reverseChase();
}

void twoOpposite() {
  for (int i = 0; i < numLEDs / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLEDs - 1 - i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[numLEDs - 1 - i], LOW);
  }
}

void fillFromStart() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
}

void fillFromEnd() {
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
}

void blinkAll() {
  digitalWriteAll(HIGH);
  delay(300);
  digitalWriteAll(LOW);
  delay(300);
}

void alternateEvenOdd() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], i % 2 == 0 ? HIGH : LOW);
  }
  delay(300);
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], i % 2 != 0 ? HIGH : LOW);
  }
  delay(300);
  clearLEDs();
}

void middleOut() {
  int mid = numLEDs / 2;
  for (int i = 0; i <= mid; i++) {
    if (mid - i >= 0) digitalWrite(ledPins[mid - i], HIGH);
    if (mid + i < numLEDs) digitalWrite(ledPins[mid + i], HIGH);
    delay(100);
  }
  clearLEDs();
}

void edgesIn() {
  for (int i = 0; i < numLEDs / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLEDs - 1 - i], HIGH);
    delay(100);
  }
  clearLEDs();
}

void shiftLeft() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWriteAll(LOW);
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
}

void shiftRight() {
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWriteAll(LOW);
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
}

void snakeForward() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    if (i > 2) digitalWrite(ledPins[i - 3], LOW);
  }
  clearLEDs();
}

void snakeBackward() {
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    if (i < numLEDs - 3) digitalWrite(ledPins[i + 3], LOW);
  }
  clearLEDs();
}

void flashOneByOne() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void doubleBounce() {
  for (int i = 0; i < numLEDs / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLEDs - 1 - i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[numLEDs - 1 - i], LOW);
  }
}

void rollingPair() {
  for (int i = 0; i < numLEDs - 1; i++) {
    digitalWriteAll(LOW);
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    delay(100);
  }
  clearLEDs();
}

void fillAndEmpty() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(50);
  }
  delay(200);
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(50);
  }
}

void randomBlink() {
  int led = random(numLEDs);
  digitalWrite(ledPins[led], HIGH);
  delay(100);
  digitalWrite(ledPins[led], LOW);
}

void runningWave() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    if (i >= 2) digitalWrite(ledPins[i - 2], LOW);
    delay(100);
  }
  clearLEDs();
}

// ----- Utility Function -----
void digitalWriteAll(int state) {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], state);
  }
}
