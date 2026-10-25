#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 11;
const int buzzPin = 12;
const int ledPin = 9;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Game Variables ---
int sequence[50];      // Stores up to 50 levels
int currentLevel = 1;  // Current game level / score
bool gameOver = false;

// Tones for Buttons 1, 2, 3, 4
const int tones[] = { 1000, 1300, 1600, 1900 };

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  randomSeed(analogRead(A0));

  showStartScreen();
}

void loop() {
  if (!gameOver) {
    // 1. Generate new step for current level
    sequence[currentLevel - 1] = random(1, 5);  // Pick 1, 2, 3, or 4

    // 2. Announce round start
    lcd.setCursor(0, 0);
    lcd.print("WATCH SEQUENCE  ");
    lcd.setCursor(0, 1);
    lcd.print("LEVEL: ");
    lcd.print(currentLevel);
    lcd.print("        ");
    delay(1000);

    // 3. Display and play each number in sequence
    for (int i = 0; i < currentLevel; i++) {
      lcd.setCursor(0, 0);
      lcd.print("NUMBER: [ ");
      lcd.print(sequence[i]);
      lcd.print(" ]  ");

      lcd.setCursor(0, 1);
      lcd.print("STEP ");
      lcd.print(i + 1);
      lcd.print(" OF ");
      lcd.print(currentLevel);
      lcd.print("    ");

      playNote(sequence[i]);
      delay(400);  // Pause between numbers for clear visual/audio separation
    }

    // 4. Player's Turn
    lcd.setCursor(0, 0);
    lcd.print("YOUR TURN!      ");
    lcd.setCursor(0, 1);
    lcd.print("PRESS BUTTONS.. ");

    for (int i = 0; i < currentLevel; i++) {
      int userPress = waitForButtonPress();

      // Show live feedback of what button was pressed
      lcd.setCursor(0, 0);
      lcd.print("YOU PRESSED: ");
      lcd.print(userPress);
      lcd.print("  ");

      playNote(userPress);

      if (userPress != sequence[i]) {
        triggerGameOver();
        return;
      }
    }

    // 5. Level Cleared!
    lcd.setCursor(0, 0);
    lcd.print("CORRECT! LEVEL  ");
    lcd.setCursor(0, 1);
    lcd.print("UP! +1          ");

    // Level-up chime
    tone(buzzPin, 1200, 100);
    delay(100);
    tone(buzzPin, 1600, 100);
    delay(100);
    tone(buzzPin, 2000, 200);
    delay(1000);

    currentLevel++;  // Advance to next round
  }
}

void playNote(int buttonNum) {
  int noteFreq = tones[buttonNum - 1];

  digitalWrite(ledPin, HIGH);
  tone(buzzPin, noteFreq, 200);
  delay(200);
  digitalWrite(ledPin, LOW);
}

// --- Debounced & Filtered Button Reader ---
int waitForButtonPress() {
  while (true) {
    if (IrReceiver.decode()) {
      // Filter out IR repeat frames (prevents single press registering twice)
      if (!(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
        uint16_t cmd = IrReceiver.decodedIRData.command;
        int btn = getButtonNum(cmd);

        if (btn >= 1 && btn <= 4) {
          IrReceiver.resume();
          delay(250);  // Debounce pause to ensure 1 press = 1 input
          return btn;  // Return valid button number (1-4)
        }
      }
      IrReceiver.resume(); // Resume listening if unmapped or repeat frame
    }
  }
}

// --- Remote Command Mapping ---
int getButtonNum(uint16_t command) {
  // Supports standard hex/dec command mappings for buttons 1, 2, 3, 4
  if (command == 0x1 || command == 0x1 || command == 22) return 1;   // Button '1'
  if (command == 0x2 || command == 0x2 || command == 25) return 2;   // Button '2'
  if (command == 0x3 || command == 0x3 || command == 13) return 3;   // Button '3'
  if (command == 0x4 || command == 0x4 || command == 12) return 4;   // Button '4'
  return -1;                                                          // Unmapped button
}

void showStartScreen() {
  lcd.setCursor(0, 0);
  lcd.print("IR SIMON SAYS!  ");
  lcd.setCursor(0, 1);
  lcd.print("PRESS ANY BUTTON");

  while (true) {
    if (IrReceiver.decode()) {
      if (!(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
        IrReceiver.resume();
        delay(300);
        break;
      }
      IrReceiver.resume();
    }
  }

  delay(500);
}

void triggerGameOver() {
  gameOver = true;

  lcd.setCursor(0, 0);
  lcd.print("GAME OVER!!     ");
  lcd.setCursor(0, 1);
  lcd.print("SCORE: ");
  lcd.print(currentLevel - 1);
  lcd.print("        ");

  // Sad defeat tones
  tone(buzzPin, 800, 200);
  delay(200);
  tone(buzzPin, 600, 200);
  delay(200);
  tone(buzzPin, 400, 400);
  delay(2000);

  // Restart Game
  currentLevel = 1;
  gameOver = false;
  showStartScreen();
}
