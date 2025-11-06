#ifndef Storage_h
#define Storage_h

#include <iostream>
#include "measurement.h"
#include <vector>
#include <cmath>


//Här lagrar jag mätningar

class MeasurementStorage {
    private:
        std::vector<Measurement> data;

    public:

    void addMeasurement(const Measurement& m);
    void printAll() const;
    void ShowStat(const std::string& sensorName);
    void SaveFile(const std::string& file) const;
    void LoadFile(const std::string& file);


};


#endif