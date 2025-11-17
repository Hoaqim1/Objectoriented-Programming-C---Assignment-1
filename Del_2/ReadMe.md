
How to run 

g++ main.cpp menu.cpp measurement.cpp storage.cpp temperature_sensor.cpp humidity_sensor.cpp pressure_sensor.cpp -o SensorProgram.exe
SensorProgram is just a name, you can name it whatever you like as long as it ends with .exe

File Structure
main.cpp
menu.cpp/h
sensor.cpp/h
temperature_sensor.cpp/h
humidity_sensor.cpp/h
pressure_sensor.cpp/h
measurement.cpp/h
storage.cpp/h
threshold.h

Features
Program reads simulated sensor values from three sensors
All values come with timestamps for when they're added

Calculations based of:
Number of measurements
Average value
Median
Minimum and maximum value
Standard deviation
This is done for every separate sensor!

You can also configure a threshold alarm
Each alarm can have a different rule
Alarms can be set to trigger above or under a specific value
Alarms triggered will have timestamps

All measurements can be saved to a file and also loaded from that file
