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
    m1.Sensor_1 = "TempSensor_1";
    m1.cUnit_1 = "C";
    m1.val = val1;
    m1.TStamp = ts;
    storage.addMeasurement(m1);

    Measurement m2;
    double val2 = humid.read();
    m2.Sensor_1 = "HumiditySensor_1";
    m2.cUnit_1 = "%";
    m2.val = val2;
    m2.TStamp = ts;
    storage.addMeasurement(m2);

    std::cout << "Value added: " << m1.Sensor_1 << m1.val << " " << m1.cUnit_1 << '\n';
    std::cout << "Value added: " << m2.Sensor_1 << m2.val << " " << m2.cUnit_1 << '\n';
}

