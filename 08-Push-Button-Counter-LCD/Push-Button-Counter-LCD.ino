#include <LiquidCrystal_I2C.h>

int pushBtnPin = 7;
int sdaPin = A4;
int sclPin = A5;
int pressCounter = 0;
int lastPushBtnStage = LOW;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(pushBtnPin, INPUT);

  lcd.init();
  lcd.backlight();
}

void checkBtnStage() {

  int currentPushBtnStage = digitalRead(pushBtnPin);

  if (currentPushBtnStage == HIGH && lastPushBtnStage == LOW) {

    pressCounter++;
    delay(50);
  }

  lastPushBtnStage = currentPushBtnStage;
}

void printIntoDis() {

  if (digitalRead(pushBtnPin) == HIGH) {

    lcd.setCursor(0, 0);
    lcd.print("Button Pressed!!");

    lcd.setCursor(0, 1);
    lcd.print("Count : ");
    lcd.print(pressCounter);
    lcd.print(" ");


  }else {

    lcd.setCursor(0, 0);
    lcd.print("Pls Press Btn!!");

    lcd.setCursor(0, 1);
    lcd.print("Count : ");
    lcd.print(pressCounter);
    lcd.print(" ");

  }
}


void loop() {

  checkBtnStage();
  printIntoDis();
}
