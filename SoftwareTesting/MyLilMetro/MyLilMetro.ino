/**
 * Attempt to make a simple metronome
 * 
 */
#include <MozziGuts.h>
#include <Metronome.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>  //SineWave Table

//Instantiate an oscillator: <table size, update rate> and wavetable 
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc1(SIN2048_DATA);

// use #define kfor CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Use Powers Of Two

//Pot analog pin
const int pitchPin4 = A4;

//var to store the bpm
int bpm =0;

//increment through each loop
static unsigned int counter;

//delay_milliseconds  how long between each occasion when ready() returns true.
Metronome myMetro(bpm);

void setup() {
  startMozzi(CONTROL_RATE);
}

void updateControl(){
  counter++;
  int pot_value4 = mozziAnalogRead(pitchPin4);
  if(myMetro.ready()){
  sineOsc4.setFreq(pot_value4);
    }

}


AudioOutput_t updateAudio(){
  int audioOut = (int)
  sineOsc1.next();
  // Note: Samples don't overlap, here, therefore this the sum is still only 8 bits range
  return MonoOutput::from8Bit(audioOut);
}


void loop() {
  audioHook();
}
