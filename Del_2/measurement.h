#pragma once
#include <string>
#include <vector>
#include <memory>


class MeasurementStorage;  
class Sensor;


struct Measurement { 
    std::string Sens;
    std::string Unit;
    double Val;
    std::string TStamp;


}; 

void getMeasurement(MeasurementStorage& storage, std::vector<std::unique_ptr<Sensor>>& sensors);

