#pragma once
#ifndef sensor_h
#define sensor_h
#include <string>

class Sensor{
    public:
        virtual ~Sensor() = default;
        virtual double read() = 0;
        virtual std::string name() const = 0;
        virtual std::string unit() const = 0;

};


#endif