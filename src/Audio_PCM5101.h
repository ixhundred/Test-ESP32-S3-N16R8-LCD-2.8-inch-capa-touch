#pragma once
#include "Arduino.h"
#include "Audio.h"
#include "SD_Card.h"

// Digital I/O used
#define I2S_DOUT      47
#define I2S_BCLK      48
#define I2S_LRC       38

#define EXAMPLE_Audio_TICK_PERIOD_MS  1

extern Audio audio;

void Play_Music_test();
void Audio_Loop();

void Audio_Init();
void Play_Music(const char* directory, const char* fileName);
void Music_pause(); 
void Music_resume();    
uint32_t Music_Duration();  
uint32_t Music_Elapsed();   
uint16_t Music_Energy();    
