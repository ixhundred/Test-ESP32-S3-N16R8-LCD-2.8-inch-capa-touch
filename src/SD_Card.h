#pragma once
#include "Arduino.h"
#include <cstring>
#include "Display_ST7789.h"
#include <SPI.h>
#include "SD.h"
#include "FS.h"

// Digital I/O used
#define SD_CS     21        //                SD_D3:  21
#define SD_MISO   16        // TFT_MISO:46    SD_D0:  16
#define SD_MOSI   17        // TFT_MOSI:45    SD_CMD: 17
#define SD_SCLK   14        // TFT_SCLK:40    SD_SCK: 14
#define SD_D1     -1        //                SD_D1:  18
#define SD_D2     -1        //                SD_D2:  15

extern uint16_t SDCard_Size;
extern uint16_t Flash_Size;

void SD_Init();
void Flash_test();

bool File_Search(const char* directory, const char* fileName);
uint16_t Folder_retrieval(const char* directory, const char* fileExtension, char File_Name[][100],uint16_t maxFiles);
