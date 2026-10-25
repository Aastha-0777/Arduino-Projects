#include<IRremote.hpp>

const int IR_RECEIVE_PIN = 11;

void setup() {
  
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver Ready! Press buttons on your remote...");

}

void loop() {
  
  if(IrReceiver.decode()){

    Serial.print("Button Hex Code: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume();

  }
  
}
