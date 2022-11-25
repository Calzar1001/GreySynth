

int switch1 = 6;
int switch2 = 7;
int switch3 = 8;
int switch4 = 10;

void setup() {
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int switchState1 = digitalRead(switch1);
  int switchState2 = digitalRead(switch2);
  int switchState3 = digitalRead(switch3);
  int switchState4 = digitalRead(switch4);

  // print out the state of the button:
  Serial.print("switch-1: ");
  Serial.print(switchState4);
  Serial.print("\t");
  Serial.print("switch-1: ");
  Serial.print(switchState3);
  Serial.print("\t");
  Serial.print("switch-1: ");
  Serial.print(switchState2);
  Serial.print("\t");
  Serial.print("switch-1: ");
  Serial.print(switchState1);
  Serial.println("\t");
  
  delay(30);        // delay in between reads for stability
}
