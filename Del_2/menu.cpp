#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include "storage.h"
#include "measurement.h"
#include "temperature_sensor.h"
#include "pressure_sensor.h"
#include "humidity_sensor.h"
#include "threshold.h"

void configureThreshold(std::vector<Threshold>& thresholds) {

    Threshold th;

    std::cout << "Vilken sensor vill du konfigurera?: ";
    std::cin >> th.sensorName;
    std::cout << "Ange ett tröskelvärde";
    std::cin >> th.limit;
    std::cout << "Ska värdet larma om det är över eller under? 1 för över och 2 för under";
    int choice;
    std::cin >> choice;
    th.over = (choice == 1);
    thresholds.push_back(th);
    std::cout << "Tröskelregel" << '\n';

    for (const auto& t : thresholds) {
        std::cout << "Tröskel: " << t.sensorName << " limit: " << th.limit << (th.over ? " (över)" : " (under)") << "\n";
    }
}
void Menu() {
    MeasurementStorage storage;
    std::vector<std::unique_ptr<Sensor>> sensors;
    std::vector<Threshold> thresholds;
    std::vector<Measurement> alarms;
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
        std::cout << "7. Tröskelregel" << '\n';

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
            getMeasurement(storage, sensors, thresholds);
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
            case 7:
            system("cls");
                configureThreshold(thresholds);
                break;
            //case 8:
            //system("cls");
                //showAlarms(alarms);
                //break;
            default:
            std::cout << "Ogiltig inmatning, välj mellan 1-6!" << '\n';
            break;
        }

    } while(choice != 6);

}