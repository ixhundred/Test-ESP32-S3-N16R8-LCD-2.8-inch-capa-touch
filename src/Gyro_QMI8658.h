#pragma once
#include <Arduino.h>
#include "I2C_Drivers.h"
#include "SensorQMI8658.hpp"      

extern IMUdata Accel;


void QMI8658_Init();
void QMI8658_Loop();
