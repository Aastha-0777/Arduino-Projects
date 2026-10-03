const int redLEDPin = 9;
const int greenLEDPin = 8;
const int blueLEDPin = 7;
//--------------------------
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;
//--------------------------
const int redPushBtnPin = 11;
const int greenPushBtnPin = 12;
const int bluePushBtnPin = 13;
//--------------------------
int redBritness, greenBritness, blueBritness;

void setup() {
  
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  //-----------------------------
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //-----------------------------
  pinMode(redPushBtnPin, INPUT);
  pinMode(greenPushBtnPin, INPUT);
  pinMode(bluePushBtnPin, INPUT);
  //-----------------------------
  
}

void checkInput(){

  redBritness = digitalRead(redPushBtnPin) ? 255 : 0;
  greenBritness = digitalRead(greenPushBtnPin) ? 255 : 0;
  blueBritness = digitalRead(bluePushBtnPin) ? 255 : 0;

}

void setColor(){

  analogWrite(redPin, redBritness);
  analogWrite(greenPin, greenBritness);
  analogWrite(bluePin, blueBritness);

}

void loop() {
  
  checkInput();

  digitalWrite(redLEDPin, digitalRead(redPushBtnPin) ? HIGH : LOW);
  digitalWrite(greenLEDPin, digitalRead(greenPushBtnPin) ? HIGH : LOW);
  digitalWrite(blueLEDPin, digitalRead(bluePushBtnPin) ? HIGH : LOW);

  setColor();

}
