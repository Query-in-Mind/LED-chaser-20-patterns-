// Define LED pins and constants
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // 10 LEDs
const int ledCount = 10; // Number of LEDs
const int patternDelay = 100; // Delay for each step in patterns (ms)
const int patternCount = 20; // Number of patterns
int currentPattern = 0; // Track current pattern

void setup() {
  // Set all LED pins as OUTPUT
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Initialize random seed for random patterns
  randomSeed(analogRead(0));
}

// Turn off all LEDs
void clearLEDs() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

// Pattern 1: Single LED chase forward
void pattern1() {
  for (int i = 0; i < ledCount; i++) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    delay(patternDelay);
  }
}

// Pattern 2: Single LED chase backward
void pattern2() {
  for (int i = ledCount - 1; i >= 0; i--) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    delay(patternDelay);
  }
}

// Pattern 3: All LEDs blink together
void pattern3() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < ledCount; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
    clearLEDs();
    delay(patternDelay);
  }
}

// Pattern 4: Even LEDs on, then odd LEDs on
void pattern4() {
  for (int i = 0; i < 5; i++) {
    clearLEDs();
    for (int j = 0; j < ledCount; j += 2) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
    clearLEDs();
    for (int j = 1; j < ledCount; j += 2) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 5: Two LEDs chasing forward
void pattern5() {
  for (int i = 0; i < ledCount - 1; i++) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    delay(patternDelay);
  }
}

// Pattern 6: Two LEDs chasing backward
void pattern6() {
  for (int i = ledCount - 1; i > 0; i--) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i - 1], HIGH);
    delay(patternDelay);
  }
}

// Pattern 7: Random single LED
void pattern7() {
  for (int i = 0; i < 10; i++) {
    clearLEDs();
    int randomLED = random(ledCount);
    digitalWrite(ledPins[randomLED], HIGH);
    delay(patternDelay);
  }
}

// Pattern 8: Middle-out chase
void pattern8() {
  int mid = ledCount / 2;
  for (int i = 0; i < mid; i++) {
    clearLEDs();
    digitalWrite(ledPins[mid + i], HIGH);
    digitalWrite(ledPins[mid - 1 - i], HIGH);
    delay(patternDelay);
  }
}

// Pattern 9: Ends to middle chase
void pattern9() {
  for (int i = 0; i < ledCount / 2; i++) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[ledCount - 1 - i], HIGH);
    delay(patternDelay);
  }
}

// Pattern 10: Fill up and empty
void pattern10() {
  clearLEDs();
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(patternDelay);
  }
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(patternDelay);
  }
}

// Pattern 11: Alternate halves
void pattern11() {
  for (int i = 0; i < 5; i++) {
    clearLEDs();
    for (int j = 0; j < ledCount / 2; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
    clearLEDs();
    for (int j = ledCount / 2; j < ledCount; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 12: Wave effect
void pattern12() {
  for (int i = 0; i < ledCount; i++) {
    clearLEDs();
    for (int j = 0; j <= i; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 13: Reverse wave effect
void pattern13() {
  for (int i = ledCount - 1; i >= 0; i--) {
    clearLEDs();
    for (int j = ledCount - 1; j >= i; j--) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 14: Ping-pong chase
void pattern14() {
  pattern1();
  pattern2();
}

// Pattern 15: Every third LED
void pattern15() {
  for (int i = 0; i < 5; i++) {
    clearLEDs();
    for (int j = 0; j < ledCount; j += 3) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
    clearLEDs();
    for (int j = 1; j < ledCount; j += 3) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 16: Random pair
void pattern16() {
  for (int i = 0; i < 10; i++) {
    clearLEDs();
    int rand1 = random(ledCount);
    int rand2 = random(ledCount);
    digitalWrite(ledPins[rand1], HIGH);
    digitalWrite(ledPins[rand2], HIGH);
    delay(patternDelay);
  }
}

// Pattern 17: Expanding center
void pattern17() {
  for (int i = 0; i < ledCount / 2; i++) {
    clearLEDs();
    for (int j = ledCount / 2 - i; j <= ledCount / 2 + i; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 18: Contracting center
void pattern18() {
  for (int i = ledCount / 2 - 1; i >= 0; i--) {
    clearLEDs();
    for (int j = ledCount / 2 - i; j <= ledCount / 2 + i; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(patternDelay);
  }
}

// Pattern 19: Single LED fast blink
void pattern19() {
  for (int i = 0; i < ledCount; i++) {
    for (int j = 0; j < 5; j++) {
      clearLEDs();
      digitalWrite(ledPins[i], HIGH);
      delay(patternDelay / 2);
      clearLEDs();
      delay(patternDelay / 2);
    }
  }
}

// Pattern 20: Knight Rider effect
void pattern20() {
  for (int i = 0; i < ledCount - 2; i++) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    digitalWrite(ledPins[i + 2], HIGH);
    delay(patternDelay);
  }
  for (int i = ledCount - 3; i >= 0; i--) {
    clearLEDs();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    digitalWrite(ledPins[i + 2], HIGH);
    delay(patternDelay);
  }
}

void loop() {
  // Run the current pattern
  switch (currentPattern) {
    case 0: pattern1(); break;
    case 1: pattern2(); break;
    case 2: pattern3(); break;
    case 3: pattern4(); break;
    case 4: pattern5(); break;
    case 5: pattern6(); break;
    case 6: pattern7(); break;
    case 7: pattern8(); break;
    case 8: pattern9(); break;
    case 9: pattern10(); break;
    case 10: pattern11(); break;
    case 11: pattern12(); break;
    case 12: pattern13(); break;
    case 13: pattern14(); break;
    case 14: pattern15(); break;
    case 15: pattern16(); break;
    case 16: pattern17(); break;
    case 17: pattern18(); break;
    case 18: pattern19(); break;
    case 19: pattern20(); break;
  }
  
  // Move to the next pattern
  currentPattern = (currentPattern + 1) % patternCount;
  delay(500); // Short pause between patterns
}