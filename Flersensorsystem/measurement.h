#include <iostream>
#ifndef measurement_h
#define measurement_h

class MeasurementStorage;  
class Sensor;


struct Measurement { 
    std::string Sensor_1;
    std::string cUnit_1;
    double val;
    std::string TStamp;


}; 

void getMeasurement(MeasurementStorage& storage, Sensor& sensor1, Sensor& sensor2);

#endif