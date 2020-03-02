cmake_minimum_required(VERSION 3.14)
project(Es4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Es4 main.cpp JobScheduler.cpp JobScheduler.h Job.cpp Job.h)