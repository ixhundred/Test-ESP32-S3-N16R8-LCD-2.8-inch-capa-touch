#include "PWR_Key.h"

static uint8_t BAT_State = 0; 
static uint8_t Device_State = 0; 
static uint16_t Long_Press = 0;
void example_increase_BAT_tick(void *arg)
{
  if(BAT_State){ 
    if(!digitalRead(PWR_KEY_PIN)){   
      if(BAT_State == 2){         
        Long_Press ++;
        if(Long_Press >= Device_Sleep_Time){
          if(Long_Press >= Device_Sleep_Time && Long_Press < Device_Restart_Time)
            Device_State = 1;
          else if(Long_Press >= Device_Restart_Time && Long_Press < Device_Shutdown_Time)
            Device_State = 2;
          else if(Long_Press >= Device_Shutdown_Time)
            Shutdown(); 
        }
      }
    }
    else{
      if(BAT_State == 1)   
        BAT_State = 2;
      Long_Press = 0;
    }
  }
}
void Fall_Asleep(void)
{

}
void Restart(void)
{

}
void Shutdown(void)
{
  digitalWrite(BAT_Control_PIN, LOW);
  digitalWrite(5, LOW);       
}
void BAT_Init(void) {
  pinMode(PWR_KEY_PIN, INPUT);    
  pinMode(BAT_Control_PIN, OUTPUT);  
  pinMode(15, OUTPUT);  
  digitalWrite(BAT_Control_PIN, LOW);
  vTaskDelay(100);
  if(!digitalRead(PWR_KEY_PIN)) {   
    BAT_State = 1;               
    digitalWrite(BAT_Control_PIN, HIGH);
  }

  const esp_timer_create_args_t BAT_tick_timer_args = {
    .callback = &example_increase_BAT_tick,
    .name = "BAT_tick"
  };
  esp_timer_handle_t BAT_tick_timer = NULL;
  esp_timer_create(&BAT_tick_timer_args, &BAT_tick_timer);
  esp_timer_start_periodic(BAT_tick_timer, EXAMPLE_BAT_TICK_PERIOD_MS * 1000);
  
}