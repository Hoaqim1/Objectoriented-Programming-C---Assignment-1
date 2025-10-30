#ifndef Sensor_h
#define Sensor_h

#include <iostream>
#include <string>


class Sensor{ 
    private:
        std::string TempSensor_1;
        std::string cUnit;
        double MinVal;
        double MaxVal;

    public:

        Sensor(std::string S1, std::string cU, double min, double max);

    double read();


};


#endif