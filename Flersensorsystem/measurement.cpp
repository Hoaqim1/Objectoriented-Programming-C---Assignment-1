#include "measurement.h"
#include "sensor.h"
#include "storage.h"
#include <ctime>
#include <iostream>

void getMeasurement(MeasurementStorage& storage, Sensor& temp, Sensor& humid) {

    time_t now = time(nullptr);
    std::string ts = ctime(&now);
    ts.pop_back();

    Measurement m1;
    double val1 = temp.read();
    m1.Sens = "TempSensor_1";
    m1.cUnit = "C";
    m1.val = val1;
    m1.TStamp = ts;
    storage.addMeasurement(m1);

    Measurement m2;
    double val2 = humid.read();
    m2.Sens = "HumiditySensor_1";
    m2.cUnit = "%";
    m2.val = val2;
    m2.TStamp = ts;
    storage.addMeasurement(m2);

    std::cout << "Value added: " << m1.Sens << m1.val << " " << m1.cUnit << '\n';
    std::cout << "Value added: " << m2.Sens << m2.val << " " << m2.cUnit << '\n';
}

