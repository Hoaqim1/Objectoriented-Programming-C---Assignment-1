#ifndef Storage_h
#define Storage_h


#include <vector>


//Här lagrar jag mätningar

class MeasurementStorage {
    private:
        std::vector<Measurement> data;

    public:
        void addMeasurement(const Measurement& m);
        void printAll() const;

};



#endif