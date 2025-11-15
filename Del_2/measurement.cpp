#include "measurement.h"
#include "sensor.h"
#include "storage.h"
#include <ctime>
#include <iostream>
#include <iomanip>

void getMeasurement(MeasurementStorage& storage, std::vector<std::unique_ptr<Sensor>>& sensors) 
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
    }
}





