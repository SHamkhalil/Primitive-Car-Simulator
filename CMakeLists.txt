cmake_minimum_required(VERSION 3.24)
project(AutoSim LANGUAGES CXX)

add_library(project_options INTERFACE)
target_compile_options(project_options INTERFACE -Wall -Wextra -Wpedantic)

add_subdirectory(sim)
add_subdirectory(apps)
add_subdirectory(tests)