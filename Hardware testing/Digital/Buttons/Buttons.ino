/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

int pushButton1 = 2;
int pushButton2 = 3;
int pushButton3 = 4;
int pushButton4 = 5;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton1, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);
  pinMode(pushButton3, INPUT_PULLUP);
  pinMode(pushButton4, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState1 = digitalRead(pushButton1);
  int buttonState2 = digitalRead(pushButton2);
  int buttonState3 = digitalRead(pushButton3);
  int buttonState4 = digitalRead(pushButton4);

  // print out the state of the button:
  Serial.print("Button-1: ");
  Serial.print(buttonState4);
  Serial.print("\t");
  Serial.print("Button-2: ");
  Serial.print(buttonState3);
  Serial.print("\t");
  Serial.print("Button-3: ");
  Serial.print(buttonState2);
  Serial.print("\t");
  Serial.print("Button-4: ");
  Serial.print(buttonState1);
  Serial.println("\t");
  
  delay(30);        // delay in between reads for stability
}
