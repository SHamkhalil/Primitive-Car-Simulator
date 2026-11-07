add_library(sim sim.cpp)
target_compile_features(sim PUBLIC cxx_std_20)
target_link_libraries(sim PRIVATE project_options)
target_include_directories(sim PUBLIC .)