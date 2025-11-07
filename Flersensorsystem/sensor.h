#ifndef Sensor_h
#define Sensor_h

#include <iostream>
#include <string>
#include <cstdlib>

//En sensor med namn, enhet, minst värde och max värde, 

class Sensor{ 
    private:
        std::string Sens;
        std::string cUnit;
        double MinVal;
        double MaxVal;

    public:
    //Konstruktorn
    Sensor(std::string, std::string, double, double);

    //Slumpvärde inom ett intervall, logik i sensor.cpp
    double read();

};


#endif