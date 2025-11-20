#pragma once
#include "sensor.h"
#include <string>

class HumiditySensor : public Sensor {
    public:
        HumiditySensor(std::string id, double minVal, double maxVal);
        double read() override;
        std::string name() const override;
        std::string unit() const override;
    private:
        std::string id_;
        double minV_, maxV_; 
};