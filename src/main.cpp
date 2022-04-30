#include <Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;

void task1code( void * parameter){
    for(;;){
        
    }
}

void task2code( void * parameter){
    for(;;){

    }
}

void setup(){

    Serial.begin(115200);

    xTaskCreatePinnedToCore(
        task1code,   /* Task function. */
        "Task1",     /* name of task. */
        10000,       /* Stack size of task */
        NULL,        /* parameter of the task */
        1,           /* priority of the task */
        &Task1,      /* Task handle to keep track of created task */
        0);          /* pin task to core 0 */    

    xTaskCreatePinnedToCore(
        task2code,   /* Task function. */
        "Task2",     /* name of task. */
        10000,       /* Stack size of task */
        NULL,        /* parameter of the task */
        1,           /* priority of the task */
        &Task2,      /* Task handle to keep track of created task */
        1);          /* pin task to core 0 */     

}

void loop(){
    
}