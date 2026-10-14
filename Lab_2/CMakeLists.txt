cmake_minimum_required(VERSION 3.16)
project(Calculator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(_calc STATIC calculator.cpp)

add_executable(calculator main.cpp)

target_link_libraries(calculator PRIVATE _calc)
