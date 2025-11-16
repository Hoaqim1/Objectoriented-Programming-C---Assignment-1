#include "measurement.h"
#include "sensor.h"
#include "storage.h"
#include "threshold.h"
#include <ctime>
#include <iostream>
#include <iomanip>

void getMeasurement(MeasurementStorage& storage, std::vector<std::unique_ptr<Sensor>>& sensors,
    std::vector<Threshold>& thresholds, std::vector<Measurement>& alarms) 
    {

    time_t now = time(nullptr);
    std::string ts = ctime(&now);
    ts.pop_back();
    
    for (auto& s : sensors) {
        double value = s->read();

        Measurement m;
        m.Sens = s->name();
        m.Unit = s->unit();
        m.Val = value;
        m.TStamp = ts;

        storage.addMeasurement(m);

        std::cout << m.Sens << " " << m.Val << " " << m.Unit << "\n";

    for (const auto& th : thresholds) {
        if (th.sensorName == m.Sens) {
            bool trigger = false;

            if (th.over && m.Val > th.limit) trigger = true;
            if (!th.over && m.Val < th.limit) trigger = true;
        
        if (trigger) {
            alarms.push_back(m);
            std::cout << "Alarm triggad hos " << m.Sens << " " << m.Val << " " << m.Unit << " " << th.over << " " << th.limit << '\n';
        }
        }
    }
    }
}