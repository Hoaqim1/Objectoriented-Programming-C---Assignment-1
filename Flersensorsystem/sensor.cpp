#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sensor.h"



    Sensor::Sensor(std::string Sens1, std::string cUnit, double MinVal, double MaxVal)
    : TempSensor_1(Sens1), cUnit(cUnit), MinVal(MinVal), MaxVal(MaxVal) {}


        //https://cplusplus.com/reference/cstdlib, https://cplusplus.com/forum/beginner/85134(REFERENCE), Ger ett flyttal mellan min och max
    double Sensor::read() {
        double range = MaxVal - MinVal;
        double slump = (double)rand() / RAND_MAX;
        return MinVal + slump * range;
}


