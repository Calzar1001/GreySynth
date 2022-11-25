// Arduino for Musicians example
// Simple Oscillator  with anolog input

#include <MozziGuts.h>
#include <Oscil.h>                  //Oscillator template
#include <tables/sin2048_int8.h>    // Sine Wave Template
////////////////////FILTER TEST///////////////
#include <tables/cos2048_int8.h> // for filter modulation
#include <LowPassFilter.h>
//////////////////////////////////////////////
//Instantiate an oscillator: <table size, update rate> and
//wavetable
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc(SIN2048_DATA);
//Osc2 Test
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc2(SIN2048_DATA);
////////////FILTER TEST////////////////////////
Oscil<COS2048_NUM_CELLS, CONTROL_RATE> kFilterMod(COS2048_DATA);
LowPassFilter lpf;
///////////////////////////////////////////////

// Use #Define for CONTROL_RATE, Not a COnstant
#define CONTROL_RATE 64 // Use Powers of 2 

const int pitchPin = A0;
const int pitchPin2 = A1;
///////FILTER//////////
const int filterPin = A3;
const int resonancePin = A4;
///////////////////////
void setup ()
{
  //setupFastAnalogRead(); // Increases the speed of reading the Analog Input
  startMozzi(CONTROL_RATE); 
}
void updateControl()
{
  int pot_value = mozziAnalogRead(pitchPin);
  //Update the frequency based on the value of the Pot
  sineOsc.setFreq(pot_value);
  int pot_value2 = mozziAnalogRead(pitchPin2);
  sineOsc2.setFreq(pot_value2);
  //////////FILTER/////////////
  int pot_value3 = mozziAnalogRead(filterPin);
  kFilterMod.setFreq(pot_value3);
  int pot_value4 = mozziAnalogRead(resonancePin);
  lpf.setResonance(pot_value4);
  ////////////////////////////
}
int updateAudio()
{
  /*
  // Returns an int Signial center around 0
  return sineOsc.next();
  return sineOsc2.next();
  */
  //////////////TEST FILTER//////
  char asig = lpf.next(sineOsc.next());
  return (int) asig;
}
void loop()
{
  audioHook(); // REQUIRED
}


