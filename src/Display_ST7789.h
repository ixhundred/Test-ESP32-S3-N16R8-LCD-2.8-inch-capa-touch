#pragma once
#include <TFT_eSPI.h>
#include "Touch_CST328.h"

extern TFT_eSPI tft;

void ST7789_Init();

void LCD_Init();
void LCD_addWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend,uint16_t* color);
