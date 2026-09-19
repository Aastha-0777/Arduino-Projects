int ledPin = 3;
int pushBtn1Pin = 13;
int pushBtn2Pin = 12;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(pushBtn1Pin, INPUT);
  pinMode(pushBtn2Pin, INPUT);

}

void loop() {
  /*
  
    WHEN PUSH BTN IS PRESSED THE INPUT BECOMES HIGH --> 1
    WHEN PUSH BTN IS UN-PRESSED THE INPUT BECOMES LOW --> 0

  */
// IT WILL STORE THE ANS opreation OF THE BOTH BTNS (PUSHED/UN-PUSHED)
// int state = digitalRead(pushBtn1Pin) && digitalRead(pushBtn2Pin);

// 2-Input AND Gate Truth Table
// ----------------------------
// Input A | Input B | Output
// --------+---------+--------
//    0    |    0    |   0
//    0    |    1    |   0
//    1    |    0    |   0
//    1    |    1    |   1


  //int currBtnStage = digitalRead(pushBtn1Pin) && digitalRead(pushBtn2Pin);

// LED WILL GLOW ACCORDINGLY
// You can Write it in One Line like this : 
  digitalWrite(ledPin, (digitalRead(pushBtn1Pin) && digitalRead(pushBtn2Pin)));

}
