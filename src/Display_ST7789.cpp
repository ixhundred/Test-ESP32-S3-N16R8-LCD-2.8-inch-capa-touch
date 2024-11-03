#include "Display_ST7789.h"

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT); /* TFT instance */
void LCD_Init() {        
  ST7789_Init();
  Touch_Init();
}

void ST7789_Init() {
  tft.begin();          /* TFT init */
  tft.setRotation( 0 ); /* Landscape orientation, flipped */
}

void LCD_addWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend,uint16_t* color) {
  uint32_t w = ( Xend - Xstart + 1 );
  uint32_t h = ( Yend - Ystart + 1 );
  tft.startWrite();
  // printf("LVG :: Xstart=%d, Ystart=%d, Xend=%d,Yend=%d\r\n",area->x1, area->y1, area->x2,area->y2);
  tft.setAddrWindow( Xstart, Ystart, w, h );
  tft.pushColors( color, w * h, true );
  tft.endWrite(); 
}

