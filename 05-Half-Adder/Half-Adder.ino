int sumLEDPin = 7;
int carryLEDPin = 6;
int btn1Pin = 12;
int btn2Pin = 11;

void setup(){

  pinMode(sumLEDPin, OUTPUT);
  pinMode(carryLEDPin, OUTPUT);
  pinMode(btn1Pin, INPUT);
  pinMode(btn2Pin, INPUT);

}

void loop(){

  int input1 = digitalRead(btn1Pin);
  int input2 = digitalRead(btn2Pin);

  int sum = (input1 ^ input2);
  int carry = (input1 && input2);

  digitalWrite(sumLEDPin, sum);
  digitalWrite(carryLEDPin, carry);

}
