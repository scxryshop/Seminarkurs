#ifndef Lidar_h
#define Lidar_h

#include "Arduino.h"
#include <RPLidar.h>
#include <Point.h>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;



class Lidar{
    public:
        Lidar(HardwareSerial ls, int PWMPin);
        void printScan();
        void getPolarPoint();
    private: 
        RPLidar lidar;
        int PWMPin;
        list<Point> derScan;
};

#endif