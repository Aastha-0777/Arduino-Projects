#include <LiquidCrystal_I2C.h>

const int buzzPin = 12;
const int sw520Pin = 3;
const int sdaPin = A4;
const int sclPin = A5;
const int ledPin = 9;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastSensorState = HIGH; // Default idle state for INPUT_PULLUP is HIGH
int knockCounter = 0;
bool isLocked = true;
unsigned long lastKnockTime = 0;
unsigned long currentKnockTime = 0;

int userGaps[4];

// --- Secret Pattern Configuration ---
// Pattern: TAP-TAP ... (pause) ... TAP-TAP-TAP (5 Knocks = 4 Gaps)
const int targetGaps[4] = { 200, 600, 200, 200 };
const int tolerance = 150; // Margin of error (+/- 150 ms)

// Function Declarations
bool validatePattern();
void resetLockedScreen();

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sw520Pin, INPUT_PULLUP);
  pinMode(buzzPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  resetLockedScreen();
}

void loop() {
  if (isLocked) {
    int currentSensorState = digitalRead(sw520Pin);

    // 1. DETECT A KNOCK (Falling Edge: HIGH -> LOW)
    if (currentSensorState == LOW && lastSensorState == HIGH) {
      currentKnockTime = millis();

      // Record time gap between consecutive knocks
      if (knockCounter > 0) {
        int gap = currentKnockTime - lastKnockTime;
        if (knockCounter - 1 < 4) {
          userGaps[knockCounter - 1] = gap;
        }
      }

      knockCounter++;
      lastKnockTime = currentKnockTime;

      // Audio & visual feedback on each knock
      digitalWrite(ledPin, LOW);
      tone(buzzPin, 1800, 50);
      delay(120); // Debounce
      digitalWrite(ledPin, HIGH);

      lcd.setCursor(0, 1); 
      lcd.print("LISTENING...    ");
    }

    // 2. TIMEOUT & PATTERN CHECK (Waits 1.2s of silence after tapping)
    if (knockCounter > 0 && isLocked && (millis() - lastKnockTime > 1200)) {
      if (validatePattern()) {
        // --- ACCESS GRANTED ---
        isLocked = false;

        lcd.setCursor(0, 0);
        lcd.print("DOOR UNLOCKED!!");
        lcd.setCursor(0, 1);
        lcd.print("ACCESS GRANTED ");

        digitalWrite(ledPin, LOW); // Turn OFF Red LED

        // Victory Unlock Chime
        tone(buzzPin, 1000, 100);
        delay(120);
        tone(buzzPin, 1500, 100);
        delay(120);
        tone(buzzPin, 2000, 250);

      } else {
        // --- ACCESS DENIED ---
        lcd.setCursor(0, 0);
        lcd.print("ACCESS DENIED ");
        lcd.setCursor(0, 1);
        lcd.print("TRY AGAIN!!   ");

        // Error Tones
        tone(buzzPin, 2000, 100);
        delay(120);
        tone(buzzPin, 1500, 100);
        delay(120);
        tone(buzzPin, 1000, 250);
        delay(1500);

        resetLockedScreen();
      }
    }

    lastSensorState = currentSensorState;
  }
}

// --- Helper Function: Check if Rhythm Matches ---
bool validatePattern() {
  if (knockCounter != 5) {
    return false; // Pattern requires exactly 5 knocks
  }

  for (int i = 0; i < 4; i++) {
    int diff = abs(userGaps[i] - targetGaps[i]);
    if (diff > tolerance) {
      return false; // Gap falls outside the +/- 150ms tolerance
    }
  }

  return true; // All 4 gaps matched!
}

// --- Helper Function: Reset Display & State ---
void resetLockedScreen() {
  knockCounter = 0;
  isLocked = true;
  digitalWrite(ledPin, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("LOCKED!!        ");
  lcd.setCursor(0, 1);
  lcd.print("ENTER PATTERN...");
}
