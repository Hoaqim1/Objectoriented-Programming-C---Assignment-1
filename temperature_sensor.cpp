#include "temperature_sensor.h"

    TemperatureSensor::TemperatureSensor(std::string id, double minVal, double maxVal) 
    : id(id), minV_(minVal), maxV_(maxVal) {}

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