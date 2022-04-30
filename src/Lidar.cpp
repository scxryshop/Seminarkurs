#include "Lidar.h"

using namespace std;

RPLidar lidar;
int PWMPin;
list<Point>derScan;
list<Point>derScanTMP;


Lidar::Lidar(HardwareSerial SerialPort, int PWMPin){
    lidar.begin(SerialPort);
    pinMode(PWMPin, OUTPUT);
    this->PWMPin = PWMPin;
}

void Lidar::collectCloud(){
    if (IS_OK(lidar.waitPoint())) {
    
    float distance = lidar.getCurrentPoint().distance; //distance value in mm unit
    float angle    = lidar.getCurrentPoint().angle; //anglue value in degree
    
    if((angle - derScanTMP.back().phi) < -180){
        derScan = derScanTMP;
        derScanTMP.clear();
    }else{
        derScanTMP.push_back(Point(distance,angle));
    }
    
  } else {
    digitalWrite(PWMPin, LOW); //stop the rplidar motor
    rplidar_response_device_info_t info;
    if (IS_OK(lidar.getDeviceInfo(info, 100))) {
       // detected...
       lidar.startScan();
       
       // start motor rotating at max allowed speed
       digitalWrite(PWMPin, HIGH);
       delay(1000);
    }
  }
}

list<Point> getScan(){
    return derScan;
}