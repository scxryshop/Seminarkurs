#include <RoboterTask.h>
#include "Arduino.h"

TaskHandle_t RoboterHandler;
int aA1,aA2,aA3,aA4;
int adistance;
int aphi;

RoboterTask::RoboterTask(){
    xTaskCreatePinnedToCore(
      loop, /* Function to implement the task */
      "RoboterTask", /* Name of the task */
      10000,  /* Stack size in words */
      NULL,  /* Task input parameter */
      0,  /* Priority of the task */
      &RoboterHandler,  /* Task handle. */
      1); /* Core where the task should run */
}

void sendCommand(int a1, int a2, int a3, int a4, int distance, int phi){
    aA1 = a1; 
    aA2 = a2; 
    aA3 = a3;
    aA4 = a4;
    adistance = distance;
    aphi = phi;
}

void loop(void * parameter){
    // loop for second core
    Serial.print("Hello Word Core 2");
}