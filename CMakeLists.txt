cmake_minimum_required(VERSION 3.9)
project(ms_sensor_lib)

set(CMAKE_CXX_STANDARD 11)

include_directories(.
                    src
                    src/temperature)
add_library(ms_sensor_lib
            src/sensor.cpp
            src/temperature/temperature.cpp
            src/lux/lux.cpp)

add_executable(ms_sensor_test test/test.cpp)

target_link_libraries(ms_sensor_test ms_sensor_lib)