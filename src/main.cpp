/*Using LVGL with Arduino requires some extra steps:
 *Be sure to read the docs here: https://docs.lvgl.io/master/get-started/platforms/arduino.html  */
#include "PWR_Key.h"
#include "Wireless.h"
#include "Gyro_QMI8658.h"
#include "RTC_PCF85063.h"
#include "SD_Card.h"
#include "Audio_PCM5101.h"
#include "LVGL_Driver.h"
#include "LVGL_Example.h"
#include "LVGL_Music.h"
void setup()
{
  Wireless_Test2();                         // 
  Flash_test();
  BAT_Init();
  I2C_Init();
  RTC_Init();
  QMI8658_Init(); 
  SD_Init();         
  Audio_Init();
  // Play_Music_test();
  LCD_Init();
  Lvgl_Init();

  Lvgl_Example1();
  // lv_demo_widgets();               
  // lv_demo_benchmark();          
  // lv_demo_keypad_encoder();     
  // lv_demo_music();  
  // lv_demo_stress();   

}

void loop()
{
    Timer_Loop();
    // Audio_Loop();
    QMI8658_Loop();
    RTC_Loop();
    // printf("BAT=%d\r\n",BAT_ADC_Read());
    vTaskDelay(2);
}
