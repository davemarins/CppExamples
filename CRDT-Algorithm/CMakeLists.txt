cmake_minimum_required(VERSION 3.14)
project(Es3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Es3 main.cpp NetworkServer.cpp NetworkServer.h SharedEditor.cpp SharedEditor.h Message.cpp Message.h Symbol.cpp Symbol.h)