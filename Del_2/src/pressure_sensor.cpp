#include "pressure_sensor.h"
#include <cstdlib>

    PressureSensor::PressureSensor(std::string id, double minVal, double maxVal) 
    : id_(id), minV_(minVal), maxV_(maxVal) {}

    double PressureSensor::read() {
        double range = maxV_ - minV_;
        double slump = (double)rand() / RAND_MAX;
        return minV_ + slump * range;
    }

    std::string PressureSensor::name() const {
        return id_;
    }

    std::string PressureSensor::unit() const {
        return "Pa";
    }