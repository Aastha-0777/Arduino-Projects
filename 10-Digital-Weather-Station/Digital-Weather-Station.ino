#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define SDAPIN A4
#define SCLPIN A5
#define PUSHBTNPIN 7

bool isFahrenheit = false;
int lastBtnStage = LOW;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  dht.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Temp : ");
  lcd.setCursor(0, 1);
  lcd.print("H:      FL: ");

  pinMode(PUSHBTNPIN, INPUT);
}

void loop() {

  int curntBtnStage = digitalRead(PUSHBTNPIN);

  if (curntBtnStage == HIGH && lastBtnStage == LOW) {

    isFahrenheit = !isFahrenheit;  // flip the flag
    delay(50);
  }

  lastBtnStage = curntBtnStage;

  float temp = dht.readTemperature(isFahrenheit);  //reads the temp in celcius you can pass true if you want in feherenhit
  float humidity = dht.readHumidity();             // reads the humidity in precentage
  float heatIndex = dht.computeHeatIndex(temp, humidity, isFahrenheit);

  if (isnan(temp) || isnan(humidity)) {

    lcd.setCursor(0, 0);
    lcd.print("Error Reading..");

    lcd.setCursor(0, 1);
    lcd.print("Check DHT11!!");

  } else {

    lcd.setCursor(6, 0);
    lcd.print(temp);

    if (isFahrenheit) {

      lcd.print("F ");

    } else {

      lcd.print("C ");
    }

    lcd.setCursor(2, 1);
    lcd.print(humidity, 1);
    lcd.print("%");

    lcd.setCursor(11, 1);
    lcd.print(heatIndex, 1);
    if (isFahrenheit) {

      lcd.print("F ");

    } else {

      lcd.print("C ");
    }
  }

  delay(200);
}
