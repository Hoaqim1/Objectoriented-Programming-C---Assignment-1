#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include "storage.h"
#include "measurement.h"
#include "temperature_sensor.h"
#include "pressure_sensor.h"
#include "humidity_sensor.h"


void Menu() {
    MeasurementStorage storage;
    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.push_back(std::make_unique<TemperatureSensor>("TempSensor_1", -10, 50));
    sensors.push_back(std::make_unique<HumiditySensor>("HumiditySensor_1", 0, 100));
    sensors.push_back(std::make_unique<PressureSensor>("PressureSensor_1", 945, 1065));
    

    int choice;

    do {

        std::cout << "1. Läs nya mätvärden från alla sensorer" << '\n';
        std::cout << "2. Visa statistik per sensor" << '\n';
        std::cout << "3. Visa alla mätvärden" << '\n';
        std::cout << "4. Spara alla mätvärden till fil" << '\n';
        std::cout << "5. Läs in mätvärden från fil" << '\n';
        std::cout << "6. Avsluta program" << '\n' << ":";

        std::cin >> choice;

        if (!std::cin) {
            std::cout << "Ogiltig inmatning" << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch(choice){
            case 1:
            system("cls");
            getMeasurement(storage, sensors);
                break;
            case 2:
            system("cls");
            storage.ShowStat("TempSensor_1");
            storage.ShowStat("HumiditySensor_1");
            storage.ShowStat("PressureSensor_1");
                break;
            case 3:
            system("cls");
            storage.printAll();
                break;
            case 4:
            system("cls");
            storage.SaveFile("Datafile.txt");
                break;
            case 5:
            system("cls");
            storage.LoadFile("Datafile.txt");
                break;
            case 6:
            system("cls");
                std::cout << "Programmet avslutas" << '\n';
                break;
            default:
            std::cout << "Ogiltig inmatning, välj mellan 1-6!" << '\n';
            break;
        }

    } while(choice != 6);

}