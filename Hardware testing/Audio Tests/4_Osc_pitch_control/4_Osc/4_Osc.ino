
//Arduino for musican mozzi Analog In Osc 4

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>  //SineWave Table
#include <LowPassFilter.h>

//Instantiate an oscillator: <table size, update rate> and wavetable 
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc2(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc3(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc4(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc5(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> sineOsc6(SIN2048_DATA);


//Create Instance of a low pass filter 
LowPassFilter lpf;

// use #define kfor CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Use Powers Of Two

const int pitchPin1 = A1;
const int pitchPin2 = A2;
const int pitchPin3 = A3;
const int pitchPin4 = A4;



void setup()
{
  startMozzi(CONTROL_RATE); // set  control rate of 64  
}

void loop()
{
  audioHook();/// Required Here
}

void updateControl()
{
  int pot_value1 = mozziAnalogRead(pitchPin1);
  sineOsc1.setFreq(pot_value1);
  int pot_value2 = mozziAnalogRead(pitchPin2);
  sineOsc2.setFreq(pot_value2);
  int pot_value3 = mozziAnalogRead(pitchPin3);
  sineOsc3.setFreq(pot_value3);
  int pot_value4 = mozziAnalogRead(pitchPin4);
  sineOsc4.setFreq(pot_value4);
  
}

int updateAudio()
{
  //return sineOsc1.next();
  return (sineOsc1.next()+sineOsc2.next()+sineOsc3.next()+sineOsc4.next()+sineOsc5.next()+sineOsc6.next()) >> 4;
}
