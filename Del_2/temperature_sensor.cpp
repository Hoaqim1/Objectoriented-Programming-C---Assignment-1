#include "temperature_sensor.h"
#include <cstdlib>


    //Konstruktor som skapar objektet TemperatureSensor, initieras med ett id och sitt min/maxvärde
    TemperatureSensor::TemperatureSensor(std::string id, double minVal, double maxVal) 
    : id_(id), minV_(minVal), maxV_(maxVal) {}

    //Slumpar ett värde mellan 0 och rand_max vilket senare skalas upp till en siffra min och max, mellan 0.0 - 1.0 är intervallet för slumpmässig siffra 
    double TemperatureSensor::read() {
        double range = maxV_ - minV_;
        double slump = (double)rand() / RAND_MAX;
        return minV_ + slump * range;
    }

    std::string TemperatureSensor::name() const {
        return id_;
    }

    std::string TemperatureSensor::unit() const {
        return "C";
    }