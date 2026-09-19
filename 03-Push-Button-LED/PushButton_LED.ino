int ledPin = 3;
int pushBtnPin = 13;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(pushBtnPin, INPUT);

}

void loop() {
  /*
  
    WHEN PUSH BTN IS PRESSED THE INPUT BECOMES HIGH --> 1
    WHEN PUSH BTN IS UN-PRESSED THE INPUT BECOMES HIGH --> 0

  */
// IT WILL STORE THE CURRENT STAGE OF THE BTN (PUSHED/UN-PUSHED)
  int currBtnStage = digitalRead(pushBtnPin);

// LED WILL GLOW ACCORDINGLY
  digitalWrite(ledPin, currBtnStage);

}
