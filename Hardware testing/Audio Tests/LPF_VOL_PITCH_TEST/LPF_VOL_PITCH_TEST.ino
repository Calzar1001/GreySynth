
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <LowPassFilter.h>
#include <tables/sin2048_int8.h> // sine table for oscillator

const char KNOB_PIN = A4; // set the input for the knob to analog pin 0
const char LDR_PIN = A3; // set the input for the LDR to analog pin 1
const char LPF_PIN = A2; // set the input for the LDR to analog pin 1

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

LowPassFilter lpf;

byte volume;

#define CONTROL_RATE 64
void setup(){
  startMozzi(CONTROL_RATE);
  Serial.begin(115200); // set up the Serial output so we can look at the piezo values // set up the Serial output so we can look at the analog levels
  lpf.setResonance(100);
}


void updateControl(){
  // read the potentiometer
  int knob_value = mozziAnalogRead(KNOB_PIN); // value is 0-1023
  int lpf_value = mozziAnalogRead(LPF_PIN);
  lpf.setCutoffFreq(lpf_value);

  // map it to an 8 bit volume range for efficient calculations in updateAudio
  volume = knob_value >> 2;  // 10 bits (0->1023) shifted right by 2 bits to give 8 bits (0->255)

  // print the value to the Serial monitor for debugging
  Serial.print("volume = ");
  Serial.print((int)volume);
  Serial.print("\t"); // prints a tab

  // read the light dependent resistor
  int light_level = mozziAnalogRead(LDR_PIN); // value is 0-1023

  // print the value to the Serial monitor for debugging
  Serial.print("light level = ");
  Serial.print(light_level);
  Serial.print("\t"); // prints a tab

  // set the frequency
  aSin.setFreq(light_level);

  Serial.println(); // next line
}


AudioOutput_t updateAudio(){
  char sample = lpf.next(aSin.next());
  // cast char output from aSin.next() to int to make room for multiplication
  return MonoOutput::from16Bit((int)sample* volume); // 8 bit * 8 bit gives 16 bits value
}


void loop(){
  audioHook(); // required here
}
