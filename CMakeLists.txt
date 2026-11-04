cmake_minimum_required(VERSION 3.24)
project(AutoSim LANGUAGES CXX)

add_executable(first main.cpp)

target_compile_features(first PRIVATE cxx_std_20)