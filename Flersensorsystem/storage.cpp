
#include <iostream>
#include "storage.h"


    //Funktioner med logik som ska användas för att hantera och sedan visa data
    void MeasurementStorage::addMeasurement(const Measurement& m)  {
        data.push_back(m);
        }

    void MeasurementStorage::printAll() const { 
        std::cout << "Mätningar" << '\n';
        for (const auto&m : data) {
            std::cout << m.TStamp << ", " << m.Sens << ", " << m.val << ", " << m.cUnit << "\n";

        }
    }

    void MeasurementStorage::ShowStat(const std::string& sensorName) {
        int val = 0;
        double sum = 0;
        double minVal = 100;
        double maxVal = -100;

    for (const auto& m : data) {
        if (m.Sens == sensorName) {
            sum += m.val;
            
            if (m.val < minVal) minVal = m.val;
            if (m.val > maxVal) maxVal = m.val;
            val++;
        }
    }

    if (val == 0) {
        std::cout << "Inga värden för " << sensorName << '\n';
        return;
    }

    double mean = sum / val;

    double StdDev = 0;
    for (const auto& m : data) {
        if (m.Sens == sensorName) {
            StdDev += (m.val - mean) * (m.val - mean);
        }
    }
    StdDev = std::sqrt(StdDev / val);

    std::cout << "Statistik för " << sensorName << "\n";
    std::cout << "Antal värden: " << val << '\n';
    std::cout << "Medelvärdet är: " << mean << '\n';
    std::cout << "Minsta värdet i listan är: " << minVal << '\n';
    std::cout << "Högsta värdet i listan är: " << maxVal << '\n';
    std::cout << "Standardavvikelsen är: " << StdDev << '\n';

}




