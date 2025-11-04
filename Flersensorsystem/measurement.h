#include <iostream>
#ifndef measurement_h
#define measurement_h

class MeasurementStorage;  
class Sensor;


struct Measurement { 
    std::string Sens;
    std::string cUnit;
    double val;
    std::string TStamp;


}; 

void getMeasurement(MeasurementStorage& storage, Sensor& sensor1, Sensor& sensor2);

#endif