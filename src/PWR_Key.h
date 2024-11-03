#pragma once
#include "Arduino.h"
#define PWR_KEY_PIN     6
#define BAT_Control_PIN 7
#define BAT_ADC_PIN     8

#define EXAMPLE_BAT_TICK_PERIOD_MS 50

#define Device_Sleep_Time    10
#define Device_Restart_Time  20
#define Device_Shutdown_Time 30

void example_increase_BAT_tick(void *arg);

void Fall_Asleep(void);
void Shutdown(void);
void Restart(void);

void BAT_Init(void);
uint16_t BAT_ADC_Read(void);