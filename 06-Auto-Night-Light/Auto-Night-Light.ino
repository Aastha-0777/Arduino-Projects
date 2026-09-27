int photoResPin = A0;
int ledPin = 3;
int roomMax = 470;
int darkMin = 26;
int ledBrightness = 0;

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int voltValue = analogRead(photoResPin);

  Serial.print("Value of Photo Sensor : ");
  Serial.println(voltValue);

  // if (voltValue <= 200 && voltValue >= 0) {

  //   digitalWrite(13, HIGH);

  // } else {

  //   digitalWrite(13, LOW);
  // }

  // 1\. Clamp readings so anything brighter than roomMax stays at roomMax
  
  if (voltValue >= 400) {
    // Replace 600 with your room light level
    ledBrightness = 0;
  } else {
    int clampedValue = constrain(voltValue, darkMin, roomMax);
    ledBrightness = map(clampedValue, darkMin, roomMax, 255, 0);
  }

  analogWrite(ledPin, ledBrightness);

  //delay(100);
}
