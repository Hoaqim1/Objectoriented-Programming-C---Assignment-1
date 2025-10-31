#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


    Sensor::Sensor(std::string TempSensor_1, std::string cUnit, double MinVal, double MaxVal)
    : TempSensor_1(S1), cUnit(cU), MinVal(min), MaxVal(max) {}


        //https://cplusplus.com/reference/cstdlib, https://cplusplus.com/forum/beginner/85134(REFERENCE)
    double Sensor::read() {
        double range = MaxVal - MinVal;
        double slump = (double)rand() / RAND_MAX;
        return min + slump * range;
}