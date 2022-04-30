#ifndef RoboterTask_h
#define RoboterTask_h

#include "Arduino.h"

class RoboterTask{
    public:
        RoboterTask();
        void sendCommand(int a1, int a2, int a3, int a4, int distance, int phi);
        void Taskloop(void * parameter);
    private: 
        TaskHandle_t RoboterHandler;
        int aA1,aA2,aA3,aA4;
        int adistance;
        int aphi;
};

#endif