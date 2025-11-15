#include "humidity_sensor.h"
#include <cstdlib>

    HumiditySensor::HumiditySensor(std::string id, double minVal, double maxVal) 
    : id(id), minV_(minVal), maxV_(maxVal) {}

    double HumiditySensor::read() {
        double range = maxV_ - minV_;
        double slump = (double)rand() / RAND_MAX;
        return minV_ + slump * range;
    }

    std::string HumiditySensor::name() const {
        return id_;
    }

    std::string HumiditySensor::unit() const {
        return "%";
    }