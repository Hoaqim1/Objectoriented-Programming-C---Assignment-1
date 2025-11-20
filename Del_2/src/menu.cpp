#include "humidity_sensor.h"
#include "measurement.h"
#include "pressure_sensor.h"
#include "storage.h"
#include "temperature_sensor.h"
#include "threshold.h"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

void configureThreshold(std::vector<Threshold> &thresholds) {

  Threshold th;

  std::cout
      << "Välj mellan TempSensor_1, HumiditySensor_1 och PressureSensor_1: ";
  std::cin >> th.sensorName;

  if (th.sensorName != "TempSensor_1" && th.sensorName != "HumiditySensor_1" &&
      th.sensorName != "PressureSensor_1") {
    std::cout << "Ogiltig inmatning, skriv in ett av alternativen!" << '\n';
    return;
  }

  std::cout << "Ange ett tröskelvärde: ";
  std::cin >> th.limit;

  if (!std::cin) {
    std::cout << "Ogiltig inmatning, skriv in ett tröskelvärde" << '\n';
    std::cin.clear();
    std::cin.ignore(100, '\n');
    return;
  }

  std::cout << "Ska värdet larma om det är över eller under? 1 för över och 2 "
               "för under"
            << '\n';
  int choice;
  std::cin >> choice;
  if (choice != 1 && choice != 2) {
    std::cout << "Ogiltig inmatning, välj mellan 1 eller 2" << '\n';
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    return;
  }
  th.over = (choice == 1);
  thresholds.push_back(th);

  std::cout << "Tröskelregel för sensor " << th.sensorName << " skapad" << '\n';
}

void showAlarms(const std::vector<Measurement> &alarms) {
  if (alarms.empty()) {
    std::cout << "Tröskelvärden har ej brutits än" << '\n';
    return;
  }
  std::cout << "Lista av alarm:" << '\n';
  for (const auto &a : alarms) {
    std::cout << a.TStamp << ", " << a.Sens << ", " << a.Val << ", " << a.Unit
              << '\n';
  }
}

void clear_console() {
  std::cout << "\033c";
}

void Menu() {
  MeasurementStorage storage;
  std::vector<std::unique_ptr<Sensor>> sensors;
  std::vector<Threshold> thresholds;
  std::vector<Measurement> alarms;
  sensors.push_back(
      std::make_unique<TemperatureSensor>("TempSensor_1", -10, 50));
  sensors.push_back(
      std::make_unique<HumiditySensor>("HumiditySensor_1", 0, 100));
  sensors.push_back(
      std::make_unique<PressureSensor>("PressureSensor_1", 945, 1065));

  int choice;

  do {

    std::cout << "1. Läs nya mätvärden från alla sensorer" << '\n';
    std::cout << "2. Visa statistik per sensor" << '\n';
    std::cout << "3. Visa alla mätvärden" << '\n';
    std::cout << "4. Spara alla mätvärden till fil" << '\n';
    std::cout << "5. Läs in mätvärden från fil" << '\n';
    std::cout << "6. Tröskelregel" << '\n';
    std::cout << "7. Lista av alarm" << '\n';
    std::cout << "8. Avsluta program" << '\n';
    std::cin >> choice;

    if (!std::cin) {
      std::cout << "Ogiltig inmatning" << '\n';
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }

    switch (choice) {
    case 1:
      clear_console();
      getMeasurement(storage, sensors, thresholds, alarms);
      break;
    case 2:
      clear_console();
      storage.ShowStat("TempSensor_1");
      storage.ShowStat("HumiditySensor_1");
      storage.ShowStat("PressureSensor_1");
      break;
    case 3:
      clear_console();
      storage.printAll();
      break;
    case 4:
      clear_console();
      storage.SaveFile("Datafile.txt");
      break;
    case 5:
      clear_console();
      storage.LoadFile("Datafile.txt");
      break;
    case 6:
      clear_console();
      configureThreshold(thresholds);
      break;
    case 7:
      clear_console();
      showAlarms(alarms);
      break;
    case 8:
      clear_console();
      std::cout << "Programmet avslutas" << '\n';
      break;

    default:
      std::cout << "Ogiltig inmatning, välj mellan 1-8!" << '\n';
      break;
    }

  } while (choice != 8);
}
