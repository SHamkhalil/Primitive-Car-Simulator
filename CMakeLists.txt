cmake_minimum_required(VERSION 3.24)
project(AutoSim LANGUAGES CXX)

add_library(sim sim.cpp)
add_library(project_options INTERFACE)

add_executable(first main.cpp)
add_executable(tests tests.cpp)

# Compiler additions
target_compile_options(project_options INTERFACE -Wall -Wextra -Wpedantic)

# Library links
target_link_libraries(sim PRIVATE project_options)
target_link_libraries(tests PRIVATE sim project_options)
target_link_libraries(first PRIVATE sim project_options)

# Compiler requirments
target_compile_features(sim PUBLIC cxx_std_20)
target_compile_features(first PRIVATE cxx_std_20)
target_compile_features(tests PRIVATE cxx_std_20)