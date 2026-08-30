/*

Binary Counter using 4 LED

0 => 0000
1 => 0001
2 => 0010
3 => 0011
4 => 0100
5 => 0101
6 => 0110
7 => 0111
8 => 1000
9 => 1001
10 => 1010
11 => 1011
12 => 1100
13 => 1101
14 => 1110
15 => 1111

HERE 1 MEANS ON AND 0 MEANS OFF

*/

int bit8 = 13;
int bit4 = 12;
int bit2 = 11;
int bit1 = 10;
int gap = 1000;

void setup() {

  pinMode(bit8, OUTPUT);
  pinMode(bit4, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit1, OUTPUT);
}

void loop() {

  // FOR 0 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 1 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 2 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 3 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 4 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 5 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 6 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 7 
  digitalWrite(bit8, LOW);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 8 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 9 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 10 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 11 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 12 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 13 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

  // FOR 14 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);

  // gap after each num 

  delay(gap);

  // FOR 15 
  digitalWrite(bit8, HIGH);
  digitalWrite(bit4, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);

  // gap after each num 

  delay(gap);

}
