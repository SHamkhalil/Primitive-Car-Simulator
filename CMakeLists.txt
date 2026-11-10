cmake_minimum_required(VERSION 3.24)
project(AutoSim LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.18.0
)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 6.2
)
FetchContent_MakeAvailable(googletest raylib)

add_library(project_options INTERFACE)
target_compile_options(project_options INTERFACE -Wall -Wextra -Wpedantic)

add_subdirectory(sim)
add_subdirectory(apps)
add_subdirectory(tests)
