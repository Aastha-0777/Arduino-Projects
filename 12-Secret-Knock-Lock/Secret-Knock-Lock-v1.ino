#include <LiquidCrystal_I2C.h>

const int buzzPin = 12;
const int sw520Pin = 3;
const int sdaPin = A4;
const int sclPin = A5;
const int ledPin = 9;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastSensorState = LOW;
int knockCounter = 0;
bool isLocked = true;
unsigned long lastKnockTime = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(sw520Pin, INPUT_PULLUP);
  pinMode(buzzPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LOCKED!!      ");
  lcd.setCursor(0, 1);
  lcd.print("KNOCK : 0/3");

  digitalWrite(ledPin, HIGH);
}

void loop() {

  if (isLocked) {

    int currentSensorState = digitalRead(sw520Pin);

    if (currentSensorState == LOW && lastSensorState == HIGH) {

      knockCounter++;

      lastKnockTime = millis();

      lcd.setCursor(8, 1);
      lcd.print(knockCounter);

      digitalWrite(ledPin, LOW);
      tone(buzzPin, 1800, 50);
      delay(120);
      digitalWrite(ledPin, HIGH);

      if (knockCounter >= 3) {

        isLocked = false;

        lcd.setCursor(0, 0);
        lcd.print("DOOR UNLOCKED!!");
        lcd.setCursor(0, 1);
        lcd.print("ACCESS GRANTED ");

        tone(buzzPin, 1000, 100);
        delay(120);
        tone(buzzPin, 1500, 100);
        delay(120);
        tone(buzzPin, 2000, 250);
      }
    }

    if (knockCounter > 0 && isLocked && (millis() - lastKnockTime > 500)) {

      knockCounter = 0;
      lcd.setCursor(0, 0);
      lcd.print("ACCESS DENIED ");
      lcd.setCursor(0, 1);
      lcd.print("TRY AGAIN!! ");

      tone(buzzPin, 2000, 100);
      delay(120);
      tone(buzzPin, 1500, 100);
      delay(120);
      tone(buzzPin, 1000, 250);
      delay(1000);

      lcd.setCursor(0, 0);
      lcd.print("LOCKED!!      ");
      lcd.setCursor(0, 1);
      lcd.print("KNOCK : 0/3");

    }

    lastSensorState = currentSensorState;
  }
}
