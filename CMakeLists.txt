cmake_minimum_required(VERSION 3.25)
project(dlc++)

add_library(dlc++ SHARED source/dl.cpp)
target_include_directories(dlc++ PUBLIC include)
