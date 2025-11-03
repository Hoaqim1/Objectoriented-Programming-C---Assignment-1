#ifndef Sensor_h
#define Sensor_h

#include <iostream>
#include <string>
#include <cstdlib>

//En sensor med namn, enhet, minst värde och max värde

class Sensor{ 
    private:
        std::string TempSensor_1;
        std::string cUnit;
        double MinVal;
        double MaxVal;

    public:
    //Konstruktorn
    Sensor(std::string S1, std::string cU, double min, double max);

    //Slumpvärde inom ett intervall
    double read();

};

void SensorTest();

#endif