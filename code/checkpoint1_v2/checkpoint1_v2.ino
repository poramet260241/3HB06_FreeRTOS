#include <Arduino_FreeRTOS.h>
#define R_LED 3
#define G_LED 4 
#define Y_LED 5
#define O_LED 6
#define PUSH_SW 2
#define POT A0
#define STACK_SIZE 100

int mode_sel = 0;
int count_show = 0;
int pot_val = 0;
int delay_time = 500;

void setup() {
 Serial.begin(9600);
 xTaskCreate(Read_Switch, "Read push button switch", STACK_SIZE, NULL, 1, NULL);
 xTaskCreate(Read_Poten, "Read Potentiometer", STACK_SIZE, NULL, 1, NULL);
 xTaskCreate(Display_R_LED, "Red LED Task", STACK_SIZE, NULL, 1, NULL);
 xTaskCreate(Display_G_LED, "Green LED Task", STACK_SIZE, NULL, 1, NULL);
 xTaskCreate(Display_Y_LED, "Yellow LED Task", STACK_SIZE, NULL, 1, NULL);
 xTaskCreate(Display_O_LED, "Orange LED Task", STACK_SIZE, NULL, 1, NULL);
 vTaskStartScheduler();
}

void Read_Poten(void *pvParameters){
  while (1){
    pot_val = analogRead(POT); // read the input pin
    Serial.println(pot_val);
    delay_time = map(pot_val, 0, 1023, 500, 1500);
  }
} 

void Display_R_LED(void *pvParameters)
{
  pinMode(R_LED, OUTPUT);
  while (1){
    if(mode_sel == 0){
      if(count_show > 4)
        count_show = 0; 
      if(count_show == 0)
        digitalWrite(R_LED, HIGH);
      else
        digitalWrite(R_LED, LOW);
    }
    else if(mode_sel == 1){
      if(count_show > 4)
        count_show = 0;
       
      if(count_show == 4)
        digitalWrite(R_LED, HIGH);
      else
        digitalWrite(R_LED, LOW);
    }
    else if(mode_sel == 2){
      if(count_show > 7)
        count_show =0;
        
      if(count_show >=1 && count_show <= 7)
        digitalWrite(R_LED, HIGH);
      else
        digitalWrite(R_LED, LOW);
    }
    else if(mode_sel == 3){
      if(count_show > 7)
        count_show = 0;
        
      if(count_show == 4)
        digitalWrite(R_LED, HIGH);
      else
        digitalWrite(R_LED, LOW);
    }
    
    vTaskDelay(pdMS_TO_TICKS(delay_time));
    count_show++;
  }
}

void Display_G_LED(void *pvParameters)
{
  pinMode(G_LED, OUTPUT);
  while (1){
    if(mode_sel == 0){
      if(count_show > 4)
        count_show = 0;
        
      if(count_show == 1)
        digitalWrite(G_LED, HIGH);
      else
        digitalWrite(G_LED, LOW);
    }
    else if(mode_sel == 1){
      if(count_show > 4)
        count_show = 0;
       
      if(count_show == 2)
        digitalWrite(G_LED, HIGH);
      else
        digitalWrite(G_LED, LOW);
    }
    else if(mode_sel == 2){
      if(count_show > 8)
        count_show =0;
        
      if(count_show >=2 && count_show <= 6)
        digitalWrite(G_LED, HIGH);
      else
        digitalWrite(G_LED, LOW);
    }
    else if(mode_sel == 3){
      if(count_show > 8)
        count_show = 0;
        
      if(count_show >=3 && count_show <= 5)
        digitalWrite(G_LED, HIGH);
      else
        digitalWrite(G_LED, LOW);
    }
    
    vTaskDelay(pdMS_TO_TICKS(delay_time));
    count_show++;
  }
}

void Display_Y_LED(void *pvParameters)
{
  pinMode(Y_LED, OUTPUT);
  while (1){
    if(mode_sel == 0){
      if(count_show > 4)
        count_show = 0;
        
      if(count_show == 2)
        digitalWrite(Y_LED, HIGH);
      else
        digitalWrite(Y_LED, LOW);
    }
    else if(mode_sel == 1){
      if(count_show > 4)
        count_show = 0;
       
      if(count_show == 1)
        digitalWrite(Y_LED, HIGH);
      else
        digitalWrite(Y_LED, LOW);
    }
    else if(mode_sel == 2){
      if(count_show > 8)
        count_show =0;
        
      if(count_show >=3 && count_show <= 5)
        digitalWrite(Y_LED, HIGH);
      else
        digitalWrite(Y_LED, LOW);
    }
    else if(mode_sel == 3){
      if(count_show > 8)
        count_show = 0;
        
      if(count_show >=2 && count_show <= 6)
        digitalWrite(Y_LED, HIGH);
      else
        digitalWrite(Y_LED, LOW);
    }
    
    vTaskDelay(pdMS_TO_TICKS(delay_time));
    count_show++;
  }
}

void Display_O_LED(void *pvParameters)
{
  pinMode(O_LED, OUTPUT);
  while (1){
    if(mode_sel == 0){
      if(count_show > 4)
        count_show = 0;
        
      if(count_show == 3)
        digitalWrite(O_LED, HIGH);
      else
        digitalWrite(O_LED, LOW);
    }
    else if(mode_sel == 1){
      if(count_show > 4)
        count_show = 0;
       
      if(count_show == 0)
        digitalWrite(O_LED, HIGH);
      else
        digitalWrite(O_LED, LOW);
    }
    else if(mode_sel == 2){
      if(count_show > 8)
        count_show =0;
        
      if(count_show == 4)
        digitalWrite(O_LED, HIGH);
      else
        digitalWrite(O_LED, LOW);
    }
    else if(mode_sel == 3){
      if(count_show > 8)
        count_show = 0;
        
      if(count_show >=1 && count_show <= 7)
        digitalWrite(O_LED, HIGH);
      else
        digitalWrite(O_LED, LOW);
    }
    
    vTaskDelay(pdMS_TO_TICKS(delay_time));
    count_show++;
  }
}

void Read_Switch(void *pvParameters){
  pinMode(PUSH_SW, INPUT);
  while (1) {
    int sw_status = digitalRead(PUSH_SW);
    if (sw_status==LOW){
      vTaskDelay(pdMS_TO_TICKS(10));
      sw_status = digitalRead(PUSH_SW);
      if (sw_status==LOW){
        while(sw_status==LOW){
          sw_status = digitalRead(PUSH_SW);
        }
        mode_sel++;
        if (mode_sel>3)
          mode_sel=0;
       }
    }
  }
}

void loop() {} 
