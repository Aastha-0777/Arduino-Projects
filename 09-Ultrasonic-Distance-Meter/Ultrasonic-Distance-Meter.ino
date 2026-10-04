#include <LiquidCrystal_I2C.h>

const int sdaPin = A4;
const int sclPin = A5;
const int trigPin = 9;
const int echoPin = 10;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();


  lcd.setCursor(0, 0);
  lcd.print("DISTANCE METER");

  lcd.setCursor(0, 1);
  lcd.print("Dist: ");

}

void loop() {
  
  // set trigPin to LOW for 2 microSec so it clears any old signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // set trigPin to HIGH for 10 microSec so it emits the 8-cycle sound pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
 
  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2;

  lcd.setCursor(6, 1);
  lcd.print(distance);
  lcd.print(" cm   ");

  delay(200);

}
