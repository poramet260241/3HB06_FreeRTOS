#include <Arduino_FreeRTOS.h>
//#define R_LED 3
//#define G_LED 4 
//#define Y_LED 5
//#define O_LED 6
//#define PUSH_SW 2
//#define POT A0

#define R_LED 8
#define G_LED 9 
#define Y_LED 10
#define O_LED 11
#define PUSH_SW 6
#define POT A0

int mode_sel=0;
int pot_val=0;
int delay_time = 500;

void setup() {
 Serial.begin(9600);
 xTaskCreate(Read_Switch, "Read push button switch", 100, NULL, 1, NULL);
 xTaskCreate(Read_Poten, "Read Potentiometer", 100, NULL, 1, NULL);
 xTaskCreate(Display_R_LED, "Red LED Task", 100, NULL, 1, NULL);
 xTaskCreate(Display_G_LED, "Green LED Task", 100, NULL, 1, NULL);
 xTaskCreate(Display_Y_LED, "Yellow LED Task", 100, NULL, 1, NULL);
 xTaskCreate(Display_O_LED, "Orange LED Task", 100, NULL, 1, NULL);
 vTaskStartScheduler();
}

void Read_Poten(void *pvParameters){
  while (1){
    pot_val = analogRead(POT); // read the input pin
    Serial.println(pot_val);
    //delay_time = map(pot_val, 0, 1023, 500, 1500);
  }
} 


void Display_R_LED(void *pvParameters)
{
  Serial.println("TESTTTT");
  pinMode(R_LED, OUTPUT);
  while (1) {
    if(mode_sel == 0){
      digitalWrite(R_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(R_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // G
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // Y
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 1){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // Y
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // G
      digitalWrite(R_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(R_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 2){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      digitalWrite(R_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGYO
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      digitalWrite(R_LED, LOW);
    }
    else if(mode_sel == 3){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      digitalWrite(R_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGYO
      digitalWrite(R_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
    }
  }
}

void Display_G_LED(void *pvParameters){
  pinMode(G_LED, OUTPUT);
  while (1) {
    if(mode_sel == 0){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      digitalWrite(G_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(G_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // Y
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 1){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // Y
      digitalWrite(G_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(G_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 2){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      digitalWrite(G_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGYO
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      digitalWrite(G_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
    }
    else if(mode_sel == 3){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OY
      digitalWrite(G_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYGR
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYG
      digitalWrite(G_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
    }
  }
}

void Display_Y_LED(void *pvParameters){
  pinMode(Y_LED, OUTPUT);
  while (1) {
    if(mode_sel == 0){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // G
      digitalWrite(Y_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(Y_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 1){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      digitalWrite(Y_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(Y_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // G
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 2){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      digitalWrite(Y_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGYO
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      digitalWrite(Y_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
    }
    else if(mode_sel == 3){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      digitalWrite(Y_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYGR
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OY
      digitalWrite(Y_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
    }
  }
}

void Display_O_LED(void *pvParameters){
  pinMode(O_LED, OUTPUT);
  while (1) {
    if(mode_sel == 0){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // G
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // Y
      digitalWrite(O_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(O_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 1){
      digitalWrite(O_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));
      digitalWrite(O_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // G
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // Y
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
    }
    else if(mode_sel == 2){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      digitalWrite(O_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGYO
      digitalWrite(O_LED, LOW);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RGY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // RG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // R
    }
    else if(mode_sel == 3){
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // E
      digitalWrite(O_LED, HIGH);
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYGR
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OYG
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // OY
      vTaskDelay(pdMS_TO_TICKS(delay_time));  // O
      digitalWrite(O_LED, LOW);
    }
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
