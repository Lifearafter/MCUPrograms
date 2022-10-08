/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = 26;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

const int bitOne = 27;
const int bitTwo = 28;
const int bitThree = 29;
const int bitFour = 30;

const int bitFive =  12;
const int bitSix = 14;
const int bitSeven = 18;
const int bitEight = 35;

const int latchEn = 36;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  pinMode(bitOne, OUTPUT);
  pinMode(bitTwo, OUTPUT);
  pinMode(bitThree, OUTPUT);
  pinMode(bitFour, OUTPUT);
  
  pinMode(bitFive, OUTPUT);
  pinMode(bitSix, OUTPUT);
  pinMode(bitSeven, OUTPUT);
  pinMode(bitEight, OUTPUT);
  
  pinMode(latchEn, OUTPUT);
  
  pinMode(analogInPin, INPUT);
}

void loop() {
  
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 99);
  
  int temp = outputValue;
  int digitOne = temp / 10;
  int digitTwo = temp % 10;
  
  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  
  Serial.print("\t digitOne = ");
  Serial.println(digitOne);
  
  Serial.print("\t digitTwo = ");
  Serial.println(digitTwo);
  
  digitalWrite(bitOne, LOW);
  digitalWrite(bitTwo, LOW);
  digitalWrite(bitThree, LOW);
  digitalWrite(bitFour, LOW);
  
  digitalWrite(bitFive, LOW);
  digitalWrite(bitSix, LOW);
  digitalWrite(bitSeven, LOW);
  digitalWrite(bitEight, LOW);
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
 // delay(2);
  
  for(int i = 0; i < 4; i++){
    int tempTwo = 0;

    switch(i){
      case 0:
        tempTwo = 12;
        break;
      case 1: 
        tempTwo = 14;
        break;
      case 2:
        tempTwo = 18;
        break;
      case 3:
        tempTwo = 35;
        break;
        
    }
    
    int temp = bitOne + i;
    
    if(bitRead(digitOne, i) == 1){
      digitalWrite(temp, HIGH);
    }
    if(bitRead(digitTwo, i) == 1){
      digitalWrite(tempTwo, HIGH);
    }
  }
  
  digitalWrite(latchEn, HIGH);
  delay(500);
  
  digitalWrite(latchEn, LOW);
}
