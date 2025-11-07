https://github.com/Hoaqim1/Objectoriented-Programming-C---Assignment-1

How to run:
g++ main.cpp menu.cpp sensor.cpp measurement.cpp storage.cpp -o Flersensorsystem.exe

Functional Requirements
Data Collection

The user can read new sensor values (simulated by random generation) – getMeasurement().

Supports multiple sensors (temperature and humidity).

Data Processing

Calculates and displays:

Number of values – ShowStat

Average – ShowStat

Minimum and maximum values – ShowStat

Standard deviation – ShowStat

User Interface (Menu)

The user can choose actions through the menu

Read new measurements from all sensors – getMeasurement

Show statistics per sensor – ShowStat

Display all stored measurements – printAll

Save all measurements to file – SaveFile

Load measurements from file – LoadFile

Exit program

Structure
File	Description
main.cpp	Starts the program, seeds the random generator, and launches the menu.
menu.cpp / menu.h	Contains the main user menu and connects user choices to logic functions.
sensor.cpp / sensor.h	Handles simulated sensors. Each Sensor object has a name, unit, and value range. The read() function returns a random float within the range.
measurement.cpp / measurement.h	Defines the Measurement struct and creates new readings with timestamps.
storage.cpp / storage.h	Contains MeasurementStorage, which stores, analyzes, and handles file I/O for all measurements.
Installation



Object-Oriented Programming

Practiced creating and connecting multiple classes (Sensor, Measurement, MeasurementStorage).

Improved understanding of how to encapsulate functionality and keep classes independent.

Possible Improvements

Implement Sensor profiles

Add options to search for time interval or date measurements or filter 

Threshold analysis

Conclusion
