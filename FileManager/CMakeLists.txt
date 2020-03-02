cmake_minimum_required(VERSION 3.14)
project(Es2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Es2 main.cpp Base.cpp Base.h Directory.cpp Directory.h File.cpp File.h DuplicateDetected.h OperationDenied.h)