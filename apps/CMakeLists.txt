add_executable(first window.cpp)

target_compile_features(first PRIVATE cxx_std_20)
target_link_libraries(first PRIVATE sim project_options raylib)
