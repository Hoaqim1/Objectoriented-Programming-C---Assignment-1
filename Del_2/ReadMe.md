https://github.com/Hoaqim1/Objectoriented-Programming-C---Assignment-1/tree/main/Del_2
How to run 

g++ main.cpp menu.cpp measurement.cpp storage.cpp temperature_sensor.cpp humidity_sensor.cpp pressure_sensor.cpp -o SensorProgram.exe
Paste in terminal:
./SensorProgram.exe
or just start the exe wherever you installed it.

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
Program reads simulated sensor values from three sensors, sensors inherit from the abstract class called Sensor
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
Alarms triggered will have timestamps with the sensor name, rule and value in it

All measurements can be saved to a file and also loaded from that file

UML-Diagram included, I'll be honest and say that it's pretty bad, I can barely draw a stick figure so might have messed up the UML.


https://app.diagrams.net/#LNamnlöst%20diagram.drawio#%7B"pageId"%3A"FoLLH0HAvn1d5P-vqN85"%7D