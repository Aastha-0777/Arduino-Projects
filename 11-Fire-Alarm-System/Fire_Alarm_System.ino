#include <LiquidCrystal_I2C.h>

const int bzzPin = 12;
const int flamPin = 2;
const int sdaPin = A4;
const int sclPin = A5;
const int ledPin = 7;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  
  pinMode(flamPin, INPUT);
  pinMode(bzzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("FIRE ALARM SYS");

}

void loop() {
  
  int flamState = digitalRead(flamPin);

  if(flamState == LOW){

    lcd.setCursor(0, 1);
    lcd.print("!! FIRE DETECTED");

    digitalWrite(ledPin, HIGH);
    tone(bzzPin, 2200);
    delay(100);

    digitalWrite(ledPin, LOW);
    tone(bzzPin, 1200);
    delay(100);

  }else{

    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE    ");

    noTone(bzzPin);
    delay(200);

  }
  
}
