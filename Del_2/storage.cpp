
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "storage.h"


    //Funktioner med logik som ska användas för att hantera och sedan visa data
    void MeasurementStorage::addMeasurement(const Measurement& m)  {
        data.push_back(m);
        }

    void MeasurementStorage::printAll() const { 
        if (data.empty()) {
            std::cout << "Inga mätvärden i listan!" << '\n';
            return;
        }
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Mätningar" << '\n';
        for (const auto&m : data) {
            std::cout << m.TStamp << ", " << m.Sens << ", " << m.Val << " " << m.Unit << "\n";

        }
    }

    void MeasurementStorage::ShowStat(const std::string& sensorName) {
        int val = 0;
        double sum = 0;
        //numeric_limits sätter ett maxvärde, vilket gör att minval alltid är högre än vad sensorerna
        //får in för värden, så minVal startar högt vilket leder till att trycket kan vara exakt 950 och då bli minval = 950
        //är tvärtom för maxVal som startar lågt vilket då alltid kan nå maxvärde som en sensor kan ha.
        double minVal = std::numeric_limits<double>::max();
        double maxVal = std::numeric_limits<double>::lowest();

    for (const auto& m : data) {
        if (m.Sens == sensorName) {
            sum += m.Val;
            
            if (m.Val < minVal) minVal = m.Val;
            if (m.Val > maxVal) maxVal = m.Val;
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
            StdDev += (m.Val - mean) * (m.Val - mean);
        }
    }
    StdDev = std::sqrt(StdDev / val);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Statistik för " << sensorName << "\n";
    std::cout << "Antal värden: " << val << '\n';
    std::cout << "Medelvärdet är: " << mean << '\n';
    std::cout << "Minsta värdet i listan är: " << minVal << '\n';
    std::cout << "Högsta värdet i listan är: " << maxVal << '\n';
    std::cout << "Standardavvikelsen är: " << StdDev << '\n' << '\n';

}
    void MeasurementStorage::SaveFile(const std::string& Datafile) const {
        std::ofstream file(Datafile);
        if (!file) {
            std::cout << "Fil kan inte sparas till" << '\n';
            return;
        }
        for (const auto& m : data) {
            file << m.TStamp << "," << m.Sens << "," << m.Val << "," << m.Unit << "\n";
        }
        file.close();
        std::cout << "Värden sparade" << '\n';
}

    void MeasurementStorage::LoadFile(const std::string&Datafile) {
        std::ifstream file(Datafile);
        if (!file) {
            std::cout << "Fil kan inte läsas" << "\n";
            return;
        }
        data.clear();
        Measurement m;
        std::string line;

        while (std::getline(file, m.TStamp, ',') && std::getline(file, m.Sens, ',')  && (file >> m.Val).ignore() && std::getline(file, m.Unit)) {
            data.push_back(m);
        
        }
        std::cout << "Värden inladdade!" << '\n';
    }




