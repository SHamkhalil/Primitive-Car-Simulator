include(GoogleTest)

add_executable(tests tests.cpp vec3tests.cpp)

target_compile_features(tests PRIVATE cxx_std_20)
target_link_libraries(tests PRIVATE sim project_options GTest::gtest_main)

gtest_discover_tests(tests)