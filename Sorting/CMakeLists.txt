cmake_minimum_required(VERSION 2.8.9)
project(Sorting) 
#Bring the headers, such as Student.h into the project
include_directories(inc)
file(GLOB SOURCES "src/*.cpp")

add_executable(Sorting ${SOURCES})