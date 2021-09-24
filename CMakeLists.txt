CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(Ly)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
add_executable(Ly main.cpp src/Accounting.cpp include/Accounting.h include/config.h)
