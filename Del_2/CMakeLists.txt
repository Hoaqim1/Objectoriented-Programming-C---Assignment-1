cmake_minimum_required(VERSION 3.20)

project(sensor-manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sensor-manager main.cpp
	src/menu.h
	src/menu.cpp
	src/storage.h
	src/storage.cpp
	src/sensor.h
	src/sensor.cpp
	src/humidity_sensor.h
	src/humidity_sensor.cpp
	src/pressure_sensor.h
	src/pressure_sensor.cpp
	src/temperature_sensor.h
	src/temperature_sensor.cpp
	src/measurement.h
	src/measurement.cpp
	src/threshold.h
)
