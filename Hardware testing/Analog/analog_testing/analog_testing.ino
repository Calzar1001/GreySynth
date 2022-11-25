/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int pot1 = analogRead(A4);
  Serial.print("Pot-1 : ");
  Serial.print(pot1);
  Serial.print(" \t");
    
  int pot2 = analogRead(A3);
  Serial.print("Pot-2 : ");
  Serial.print(pot2);
  Serial.print(" \t");


  int pot3 = analogRead(A2);
  Serial.print("Pot-3 : ");
  Serial.print(pot3);
  Serial.print(" \t");

  
  int pot4 = analogRead(A1);
  Serial.print("Pot-4 : ");
  Serial.print(pot4);
  Serial.println("\t");
  delay(30);        // delay in between reads for stability
}
